#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3_image/SDL_image.h>
#include "Map.h"
#include <vector>
//position on the screen
struct Position{
    float x;
    float y; 
};

//used to determine where we are on the map, that way we dont turn
//where we can't
struct MapPosition{
    int x;
    int y;
};

typedef enum {
        NONE,
		WEST,
        EAST,
        NORTH,
        SOUTH
} Direction;

class Player{
    private:
        Position position;
        MapPosition mapPosition;
        Direction dir;
        std::vector<SDL_Texture*> texturesList;  
        int textureIndex;      
        SDL_Surface* surface;
        int velocity;
        Direction nextDir = NONE; 
        bool hasStartedMoving;
    public:

    bool getIfMoving() const{
        return hasStartedMoving;
    }

    Position getPosition(){
        return position;
    }

    MapPosition getMapPosition(){
        return mapPosition;
    }
    SDL_Surface* getSurface(){
        return this->surface;
    }

    void updatePosition(double deltaTime, Map &map) {
        float moveSpeed = 3.5 * 16 * deltaTime; 
    
        float newX = position.x;
        float newY = position.y;
    
        // Store next intended direction
        if (nextDir != NONE && isAlignedWithGrid()) {
            bool canTurn = false;
            switch(nextDir) {
                case WEST:
                    canTurn = canMove(mapPosition.x - 1, mapPosition.y, map);
                    break;
                case EAST:
                    canTurn = canMove(mapPosition.x + 1, mapPosition.y, map);
                    break;
                case NORTH:
                    canTurn = canMove(mapPosition.x, mapPosition.y - 1, map);
                    break;
                case SOUTH:
                    canTurn = canMove(mapPosition.x, mapPosition.y + 1, map);
                    break;
                case NONE:
                    break;
            }
            if (canTurn) {
                dir = nextDir;
                nextDir = NONE;
            }
        }
    
        // First update the map position based on current pixel position
        mapPosition.x = round((position.x - MAP_OFFSET_X + 8) / 16.0);
        mapPosition.y = round((position.y - MAP_OFFSET_Y + 8) / 16.0);
    
        // Check if we can move in the current direction before applying movement
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
    
        // Enable animation only after first EAST or WEST movement
        if (!hasStartedMoving && (dir == EAST || dir == WEST)) {
            hasStartedMoving = true;
        }

        if (canMoveInDirection) {
            switch(dir) {
                case WEST:
                    newX -= moveSpeed;
                    break;
                case EAST:
                    newX += moveSpeed;
                    break;
                case NORTH:
                    newY -= moveSpeed;
                    break;
                case SOUTH:
                    newY += moveSpeed;
                    break;
                case NONE:
                    return;
            }
        }
    
        position.x = newX;
        position.y = newY;
    }

    bool isAlignedWithGrid() {
        if (hasStartedMoving == false){
            return true;
        }
        float centerX = MAP_OFFSET_X + (mapPosition.x * 16) - 6;
        float centerY = MAP_OFFSET_Y + (mapPosition.y * 16) - 6;
        return abs(position.x - centerX) < 2 && abs(position.y - centerY) < 2;
    }
    
    
    void setDirection(SDL_Event &event) {
        Direction newDir = NONE;
        if(event.key.key == SDLK_LEFT) {
            newDir = WEST;
        }
        else if (event.key.key == SDLK_RIGHT) {
            newDir = EAST;
        }
        else if(event.key.key == SDLK_UP) {
            newDir = NORTH;
        }
        else if (event.key.key == SDLK_DOWN) {
            newDir = SOUTH;
        }
        
        nextDir = newDir;
    }
    

    
    bool canMove(int newX, int newY, Map &map) {
        if (!map.isInBounds(newX, newY)) return false;
        return map.getMapTile(newY, newX) != W;
    }
    

    SDL_Texture* getPlayerTexture(){
        return texturesList[textureIndex];
    }

    int getTextureIndex(){
        return textureIndex;
    }

    Direction getDirection(){
        return dir;
    }

    void setTextureIndex(int i){
        textureIndex = i;
    }

    void setPlayerTexture(SDL_Texture* text, int index){
        texturesList[index] = text;
    }

    //pacman starts in between two nodes, so we snap the left or the right
    //based on the first user input, the true start position you could say.
    void updateStart(){
        if (dir == EAST){
            mapPosition.x +=1;
       }
    }

    const int MAP_OFFSET_X = 76;
    const int MAP_OFFSET_Y = 53;
    
    Player() {
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
    
};
#endif