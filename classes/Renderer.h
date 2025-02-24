#ifndef RENDERER_H
#define RENDERER_H
#include <SDL3/SDL.h>
#include "Map.h"
#include "Player.h"
#include "Sprite.h"
namespace Renderer{
    void DrawPlayer(SDL_Renderer *renderer, Player &player);
    void DrawMap(SDL_Renderer *renderer, Map &map);

    void freeMapSurface(Map& map);

    void freePlayerSurface(Player& player);
}
#endif