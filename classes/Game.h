#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "DataTypes.h"
class Game{
    private:
        int score{};
        SDL_Texture* textures[11] = {nullptr};;
    public:
        Game(SDL_Renderer* renderer);
        void updateScore(int scoreUpdate);
        int getScore();
        SDL_Texture* getTexture(int i);
};
#endif