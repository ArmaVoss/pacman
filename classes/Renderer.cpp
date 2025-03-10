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

    const int MAP_OFFSET_X = 76;
    const int MAP_OFFSET_Y = 53;
    void DrawMap(SDL_Renderer *renderer, Map &map, Sprite (&sprites)[31][28]){
        SDL_FRect destRect = {76, 52, 448, 496}; 
        SDL_RenderTexture(renderer, map.getTexture(), NULL, &destRect); 
        for(int y = 0; y < 31; y++){
            for(int x = 0; x < 28; x++){
                DrawSprite(renderer, sprites[y][x], MapPosition{x, y});
            }
        }
    }


    void DrawSprite(SDL_Renderer *renderer, Sprite& sprite, MapPosition pos){
        //draw sprite while it hasn't been collected
        if (!sprite.getIsCollected()){
            SDL_FRect destRect = {
                static_cast<float>(MAP_OFFSET_X + (pos.x * 16)),
                static_cast<float>(MAP_OFFSET_Y + (pos.y * 16)),
                16, 
                16  
            };
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