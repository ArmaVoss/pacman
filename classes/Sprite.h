#ifndef SPRITE_H
#define SPRITE_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Sprite{
    private:
    bool isPowerUp;
    bool isNotCollected = false;
    SDL_Texture* texture;

    public:
    Sprite(bool powerUp);
    SDL_Texture* getTexture();
    bool getIsCollected();
    void setCollected();
};

#endif