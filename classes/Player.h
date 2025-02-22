#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3_image/SDL_image.h>
#include "Map.h"
struct Position{
    float x;
    float y; 
};


typedef enum {
		WEST,
        EAST,
        NORTH,
        SOUTH
} Direction;

class Player{
    private:
        Position position;
        Direction dir;
        SDL_Surface* surface;
        int velocity;
    public:
    Position getPosition(){
        return position;
    }
    SDL_Surface* getSurface(){
        return this->surface;
    }

    void updatePosition(){
        switch(dir){
            case WEST:
            position.x -= 2;
            break;
            case EAST:
            position.x += 2;
            break;
            case NORTH: 
            position.y -= 2;   
            break;    
            case SOUTH:
            position.y += 2;
            break;
        }
    }

    void setDirection(SDL_Event &event){
        if(event.key.key == SDLK_LEFT){
            dir = WEST;
        }
        else if (event.key.key == SDLK_RIGHT){
            dir = EAST;
        }
        else if(event.key.key == SDLK_UP){
            dir = NORTH;
        }
        else if (event.key.key == SDLK_DOWN){
            dir = SOUTH;
        }
    }

    Player(){
        surface = IMG_Load("../sprites/pacman/2.png"); 
        position.x = 16.9 * 16;
        position.y = 25.9 * 16;
    }
};
#endif