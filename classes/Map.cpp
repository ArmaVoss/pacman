#include "Map.h"
#include "iostream"
tile tempMap[28][31] =
{ 
        {W,W,W,W,W,W,W,W,W,W,W,W,n,n,n,W,P,W,n,n,n,W,W,W,W,W,W,W,W,W,W},
        {W,o,o,o,o,W,W,O,o,o,o,W,n,n,n,W,n,W,n,n,n,W,o,o,o,o,O,o,o,o,W},
        {W,o,W,W,o,W,W,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,o,o,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,W,W,W,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,n,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
        {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
        {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,o,o,o,W,W,o,n,n,n,n,n,n,n,n,n,W,W,o,o,o,o,W,W,W,o,W},
        {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,W,W,W,n,W,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,n,n,W,n,W,W,o,W,W,o,W,W,W,o,W},
        {W,o,o,o,o,W,W,o,o,o,o,W,W,n,W,W,n,n,W,n,n,n,o,W,W,o,o,o,o,o,W},
        {W,o,W,W,W,W,W,n,W,W,W,W,W,n,W,W,n,n,G,n,W,W,W,W,W,o,W,W,W,W,W},
        {W,o,W,W,W,W,W,n,W,W,W,W,W,n,W,W,n,n,G,n,W,W,W,W,W,o,W,W,W,W,W},
        {W,o,o,o,o,W,W,o,o,o,o,W,W,n,W,W,n,n,W,n,n,n,o,W,W,o,o,o,o,o,W},
        {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,n,n,W,n,W,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,W,W,o,W,W,o,W,W,n,W,W,W,W,W,n,W,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,o,o,o,W,W,o,n,n,n,n,n,n,n,n,n,W,W,o,o,o,o,W,W,W,o,W},
        {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
        {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,n,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
        {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,n,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,W,W,W,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,o,o,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
        {W,o,W,W,o,W,W,o,W,W,o,W,n,n,n,W,n,W,n,n,n,W,o,W,W,o,W,W,W,o,W},
        {W,o,o,o,o,W,W,O,o,o,o,W,n,n,n,W,n,W,n,n,n,W,o,o,o,o,O,o,o,o,W},
        {W,W,W,W,W,W,W,W,W,W,W,W,n,n,n,W,P,W,n,n,n,W,W,W,W,W,W,W,W,W,W}
};

int Map::getXExtent() const{
    return xExtent;
}

int Map::getYExtent() const{
    return yExtent;
}

tile Map::getMapTile(int i, int j) const {
    return PacmanMap[i][j];
}


SDL_Surface* Map::getSurface(){
    return this->surface;
}

bool Map::isInBounds(int i, int j){
    if (i >= 0 && i < xExtent-1 && j>=0 && j < yExtent-1){
        return true;
    }
    return false;
}

SDL_Texture* Map::getTexture(){
    return text;
}

void Map::setTexture(SDL_Texture* texture){
    text = texture;
}

void Map::rotateLeft(tile original[28][31], tile rotated[31][28]) {
    for (int i = 0; i < 28; ++i) {
        for (int j = 0; j < 31; ++j) {
            rotated[31 - j - 1][i] = original[i][j];
        }
    }
}


Map::Map(){
    surface = IMG_Load("../sprites/map/map.png"); 
    rotateLeft(tempMap, PacmanMap);
}