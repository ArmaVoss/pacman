#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3_image/SDL_image.h>
#include <vector>
#include "DataTypes.h"

class Map;

class Player {
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
    Player();
    
    bool getIfMoving() const;
    Position getPosition();
    MapPosition getMapPosition();
    SDL_Surface* getSurface();
    
    void updatePosition(double deltaTime, Map &map);
    bool isAlignedWithGrid();
    void setDirection(SDL_Event &event);
    bool canMove(int newX, int newY, Map &map);
    
    SDL_Texture* getPlayerTexture();
    int getTextureIndex();
    Direction getDirection();
    void setTextureIndex(int i);
    void setPlayerTexture(SDL_Texture* text, int index);
    void updateStart();

    const int MAP_OFFSET_X = 76;
    const int MAP_OFFSET_Y = 53;
};

#endif
