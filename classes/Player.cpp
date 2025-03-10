#include "Player.h"
#include "Map.h"
Player::Player() {
    surface = IMG_Load("../sprites/pacman/2.png");
    for (int i = 0; i < 3; i++) {
        SDL_Texture* texture;
        texturesList.push_back(texture);
    }
    textureIndex = 0;

    mapPosition.x = 14;
    mapPosition.y = 23;

    position.x = MAP_OFFSET_X + (mapPosition.x * 16 - 8) - 6;
    position.y = MAP_OFFSET_Y + (mapPosition.y * 16) - 6;
    hasStartedMoving = false;
}

bool Player::getIfMoving() const {
    return hasStartedMoving;
}

Position Player::getPosition() {
    return position;
}

MapPosition Player::getMapPosition() {
    return mapPosition;
}

SDL_Surface* Player::getSurface() {
    return this->surface;
}

void Player::updatePosition(double deltaTime, Map &map) {
    float moveSpeed = 3.5 * 16 * deltaTime; 

    float newX = position.x;
    float newY = position.y;

    if (nextDir != NONE && isAlignedWithGrid()) {
        bool canTurn = false;
        switch(nextDir) {
            case WEST: canTurn = canMove(mapPosition.x - 1, mapPosition.y, map); break;
            case EAST: canTurn = canMove(mapPosition.x + 1, mapPosition.y, map); break;
            case NORTH: canTurn = canMove(mapPosition.x, mapPosition.y - 1, map); break;
            case SOUTH: canTurn = canMove(mapPosition.x, mapPosition.y + 1, map); break;
            case NONE: break;
        }
        if (canTurn) {
            dir = nextDir;
            nextDir = NONE;
        }
    }

    mapPosition.x = round((position.x - MAP_OFFSET_X + 8) / 16.0);
    mapPosition.y = round((position.y - MAP_OFFSET_Y + 8) / 16.0);

    bool canMoveInDirection = true;
    switch(dir) {
        case WEST:
            if (!canMove(mapPosition.x - 1, mapPosition.y, map)) {
                float wallEdge = MAP_OFFSET_X + (mapPosition.x * 16) - 6;
                if (position.x - moveSpeed < wallEdge) {
                    canMoveInDirection = false;
                    newX = wallEdge;
                }
            }
            break;
        case EAST:
            if (!canMove(mapPosition.x + 1, mapPosition.y, map)) {
                float wallEdge = MAP_OFFSET_X + (mapPosition.x * 16) - 6;
                if (position.x + moveSpeed > wallEdge) {
                    canMoveInDirection = false;
                    newX = wallEdge;
                }
            }
            break;
        case NORTH:
            if (!canMove(mapPosition.x, mapPosition.y - 1, map)) {
                float wallEdge = MAP_OFFSET_Y + (mapPosition.y * 16) - 6;
                if (position.y - moveSpeed < wallEdge) {
                    canMoveInDirection = false;
                    newY = wallEdge;
                }
            }
            break;
        case SOUTH:
            if (!canMove(mapPosition.x, mapPosition.y + 1, map)) {
                float wallEdge = MAP_OFFSET_Y + (mapPosition.y * 16) - 6;
                if (position.y + moveSpeed > wallEdge) {
                    canMoveInDirection = false;
                    newY = wallEdge;
                }
            }
            break;
        case NONE:
            return;
    }

    if (!hasStartedMoving && (dir == EAST || dir == WEST)) {
        hasStartedMoving = true;
    }

    if (canMoveInDirection) {
        switch(dir) {
            case WEST: newX -= moveSpeed; break;
            case EAST: newX += moveSpeed; break;
            case NORTH: newY -= moveSpeed; break;
            case SOUTH: newY += moveSpeed; break;
            case NONE: return;
        }
    }

    if (mapPosition.x >= map.getXExtent()) {
        mapPosition.x = 0;
        newX = MAP_OFFSET_X + (mapPosition.x * 16) - 6;
    }

    // Check if Pac-Man exits the left boundary
    if (mapPosition.x < 0) {
        mapPosition.x = map.getXExtent() - 1;
        newX = MAP_OFFSET_X + (mapPosition.x * 16) - 6;
    }

    position.x = newX;
    position.y = newY;
}

bool Player::isAlignedWithGrid() {
    if (!hasStartedMoving) return true;
    
    float centerX = MAP_OFFSET_X + (mapPosition.x * 16) - 6;
    float centerY = MAP_OFFSET_Y + (mapPosition.y * 16) - 6;
    return abs(position.x - centerX) < 2 && abs(position.y - centerY) < 2;
}

void Player::setDirection(SDL_Event &event) {
    Direction newDir = NONE;
    if(event.key.key == SDLK_LEFT) newDir = WEST;
    else if (event.key.key == SDLK_RIGHT) newDir = EAST;
    else if(event.key.key == SDLK_UP) newDir = NORTH;
    else if (event.key.key == SDLK_DOWN) newDir = SOUTH;
    
    nextDir = newDir;
}

bool Player::canMove(int newX, int newY, Map &map) {
    int mapWidth = map.getXExtent(); // Get the width of the map in tiles

    // Allow teleporting through tunnels
    if (newX < 0 || newX >= mapWidth) {
        return true; // Allow movement through tunnel
    }

    if (!map.isInBounds(newX, newY)) return false;
    return map.getMapTile(newY, newX) != W;
}


SDL_Texture* Player::getPlayerTexture() {
    return texturesList[textureIndex];
}

int Player::getTextureIndex() {
    return textureIndex;
}

Direction Player::getDirection() {
    return dir;
}

void Player::setTextureIndex(int i) {
    textureIndex = i;
}

void Player::setPlayerTexture(SDL_Texture* text, int index) {
    texturesList[index] = text;
}

void Player::updateStart() {
    if (dir == EAST) {
        mapPosition.x += 1;
    }
}
