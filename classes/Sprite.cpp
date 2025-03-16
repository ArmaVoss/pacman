#include "Sprite.h"

Sprite::Sprite(){};

Sprite::Sprite(bool powerUp){
    isPowerUp = powerUp;
}

SDL_Texture* Sprite::getTexture(){
    return texture;
}

bool Sprite::getIsCollected(){
    return isNotCollected;
}

void Sprite::setCollected(){
    isNotCollected = true;
}

void Sprite::setPowerUp(bool powerUp){
    isPowerUp = powerUp;
}

void Sprite::setSpriteTexture(SDL_Texture* text){
    texture = text;
}
