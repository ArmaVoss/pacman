#ifndef RENDERER_H
#define RENDERER_H
#include <SDL3/SDL.h>
#include "Map.h"
#include "Player.h"
namespace Renderer{
    void DrawPlayer(SDL_Renderer *renderer, Player &player);
    void DrawMap(SDL_Renderer *renderer, Map &map);
}
#endif