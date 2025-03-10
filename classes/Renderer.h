#ifndef RENDERER_H
#define RENDERER_H
#include <SDL3/SDL.h>
#include "Map.h"
#include "Player.h"
#include "Sprite.h"
#include "DataTypes.h"
namespace Renderer{
    void DrawPlayer(SDL_Renderer *renderer, Player &player);
    void DrawMap(SDL_Renderer *renderer, Map &map, Sprite (&sprites)[31][28]);
    void DrawSprite(SDL_Renderer *renderer, Sprite& sprite, MapPosition pos);

    void freeMapSurface(Map& map);

    void freePlayerSurface(Player& player);
}
#endif