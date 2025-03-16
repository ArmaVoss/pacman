#include "Game.h"

Game::Game(SDL_Renderer* renderer){
    for (int i = 0; i<10; i++){
        textures[i] = SDL_CreateTextureFromSurface(renderer, IMG_Load(uiScore[i].c_str()));
    }
    textures[10] = SDL_CreateTextureFromSurface(renderer, IMG_Load(uiScore[10].c_str()));
}

void Game::updateScore(int scoreUpdate){
    score += scoreUpdate;
}

int Game::getScore(){
    return score;
} 

SDL_Texture* Game::getTexture(int i){
    return textures[i];
}

