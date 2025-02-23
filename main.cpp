#include <iostream>
#include <SDL3/SDL.h>
#include "classes/Renderer.h"
#include "classes/Map.h"
#include "classes/Player.h"

const double DELTA_TIME = 1.0 / 30.0;  
const double ANIMATION_SPEED = 0.1;   

int main(int argc, char *argv[]) {
    bool running = true;

    SDL_Window *window;
    SDL_Event event;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Pacman", 592, 592, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    Map gameMap;
    Player player;
    player.setPlayerTexture(SDL_CreateTextureFromSurface(renderer, IMG_Load("../sprites/pacman/2.png")), 0);
    player.setPlayerTexture(SDL_CreateTextureFromSurface(renderer, IMG_Load("../sprites/pacman/1.png")), 1);
    player.setPlayerTexture(SDL_CreateTextureFromSurface(renderer, IMG_Load("../sprites/pacman/0.png")), 2);

    gameMap.setTexture(SDL_CreateTextureFromSurface(renderer, gameMap.getSurface()));
    Renderer::freePlayerSurface(player);
    Renderer::freeMapSurface(gameMap);

    bool firstMove = false;

    Uint64 t_last_update = SDL_GetPerformanceCounter();
    double accumulator = 0.0;
    double animationTimer = 0.0;

    while (running) {
        // Calculate delta time
        Uint64 t_now = SDL_GetPerformanceCounter();
        double deltaTime = (double)(t_now - t_last_update) / SDL_GetPerformanceFrequency();
        t_last_update = t_now;
        accumulator += deltaTime;
        animationTimer += deltaTime;

        // Handle input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            else if (event.type == SDL_EVENT_KEY_DOWN) {
                player.setDirection(event);
                if (!firstMove) {
                    firstMove = true;
                    player.updateStart();
                }
            }
        }

        while (accumulator >= DELTA_TIME) {
            player.updatePosition(DELTA_TIME, gameMap);
            accumulator -= DELTA_TIME;
        }

        if (animationTimer >= ANIMATION_SPEED && player.getIfMoving()) {
            int index = player.getTextureIndex();
            index = (index + 1) % 3;
            player.setTextureIndex(index);
            animationTimer = 0.0;
        }

        // Rendering
        SDL_RenderClear(renderer);
        Renderer::DrawMap(renderer, gameMap);
        Renderer::DrawPlayer(renderer, player);
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
