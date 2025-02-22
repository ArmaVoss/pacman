#include "Map.h"

int Map::getXExtent() const{
    return xExtent;
}

int Map::getYExtent() const{
    return yExtent;
}

char Map::getMapTile(int i, int j) const{
    return PacmanMap[i][j];
}

SDL_Surface* Map::getSurface(){
    return this->surface;
}

bool Map::isInBounds(int i, int j){
    if (i > 0 && i < xExtent && j>0 && j < yExtent){
        return true;
    }
    return false;
}

Map::Map(){
    surface = IMG_Load("../sprites/map/map.png"); 
}