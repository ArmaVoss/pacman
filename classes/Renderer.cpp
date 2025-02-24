#include "Renderer.h"

namespace Renderer
{
    void DrawPlayer(SDL_Renderer *renderer, Player &player) {
        Position pos = player.getPosition();
        SDL_FRect destRect = {
            static_cast<float>(pos.x), 
            static_cast<float>(pos.y), 
            28, 
            28
        };
        double angle = 0.0;
        switch (player.getDirection()) {
            case EAST:  angle = 180.0; break;  
            case WEST:  angle = 0.0;   break;  
            case NORTH: angle = 90.0;  break;  
            case SOUTH: angle = 270.0; break; 
            default:    angle = 0.0;   break;  
        }

        SDL_RenderTextureRotated(renderer, player.getPlayerTexture(), NULL, &destRect, angle, NULL, SDL_FLIP_NONE);
    }

    void DrawMap(SDL_Renderer *renderer, Map &map){
        SDL_FRect destRect = {76, 52, 448, 496}; 
        SDL_RenderTexture(renderer, map.getTexture(), NULL, &destRect);
    }


    void DrawSprite(SDL_Renderer *renderer, Sprite& sprite){
        //draw sprite while it hasn't been collected
        if (!sprite.getIsCollected()){
            SDL_FRect destRect; //todo
            SDL_RenderTexture(renderer, sprite.getTexture(), NULL, &destRect);
        }
    }

    void freeMapSurface(Map& map){
        SDL_DestroySurface(map.getSurface());

    }

    void freePlayerSurface(Player& player){
        SDL_DestroySurface(player.getSurface());
    }
}