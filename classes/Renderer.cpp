#include "Renderer.h"

namespace Renderer
{
    //have a function to print image to screen
    //  -should free the memory after 


    //Function to render texture to screen if it fails
    //Return false, other true on success
    void DrawPlayer(SDL_Renderer *renderer, Player &player){
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, player.getSurface());
        Position pos = player.getPosition();
        SDL_FRect destRect = {static_cast<float>(pos.x), static_cast<float>(pos.y), 28, 28}; 
        SDL_RenderTexture(renderer, texture, NULL, &destRect);
        SDL_DestroyTexture(texture);
    }


    void DrawMap(SDL_Renderer *renderer, Map &map){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer); // Clear screen once before rendering
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, map.getSurface());
        SDL_FRect destRect = {76, 53, 448, 496}; 
        SDL_RenderTexture(renderer, texture, NULL, &destRect);
        SDL_DestroyTexture(texture);
    }
}