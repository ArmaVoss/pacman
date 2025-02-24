#include "Sprite.h"

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
