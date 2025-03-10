#ifndef SPRITE_H
#define SPRITE_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "DataTypes.h"

class Sprite{
    private:
    bool isPowerUp;
    bool isNotCollected = false;
    SDL_Texture* texture;

    public:
    Sprite();
    Sprite(bool powerUp);
    SDL_Texture* getTexture();
    bool getIsCollected();
    void setCollected();
    void setPowerUp(bool powerUp);
    void setSpriteTexture(SDL_Texture* text);
};

#endif