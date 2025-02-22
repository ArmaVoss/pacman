#include "classes/Renderer.h"
#include "classes/Map.h"
#include "classes/Player.h"

///////////////////////////////Goals/////////////////////////////
// - Create a map for pacman
// 		- Start by textual representation
//		- Would like to read map from file
//		- Then render that map with corresponding texture values
// - Create a player class
////////////////////////////End of Goals/////////////////////////


int main(int argc, char *argv[]) {
	bool running{true};

	//create window 
	SDL_Window *window;
	SDL_Event event;

	//to create a texture we need a renderer a texture and a Frect
	//Frect is a rectangle with origin on the upper left
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_FRect r;


	//initialize SDL3
	SDL_Init(SDL_INIT_VIDEO);

	//initialize important stuff
	window = SDL_CreateWindow("Pacman", 600, 600, SDL_WINDOW_RESIZABLE);

	//check for window creation error
	if (window == NULL){
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return 1;
	}	

	Map gameMap;
	Player player;

	renderer = SDL_CreateRenderer(window, NULL);
	const int FPS = 30;
    const int FRAME_DELAY = 1000 / FPS;  // 33ms per update

    Uint64 lastUpdate = SDL_GetTicks();  // Last update time
    Uint64 accumulator = 0;   
	//game loop
	while (running){		
		Uint64 frameStart = SDL_GetTicks();  // Start time of this frame
		//event loop
		while(SDL_PollEvent(&event)){
			if (event.type == SDL_EVENT_QUIT){
				running = false;
			}
			else if (event.type == SDL_EVENT_KEY_DOWN){
				player.setDirection(event);
			}
		}

		// Calculate elapsed time since last frame
		Uint64 currentTime = SDL_GetTicks();
		Uint64 deltaTime = currentTime - lastUpdate;
		lastUpdate = currentTime;

		// Accumulate time
		accumulator += deltaTime;

		// Only update player when enough time has accumulated (30 FPS logic update)
		while (accumulator >= FRAME_DELAY) {
			player.updatePosition();
			accumulator -= FRAME_DELAY;  // Remove processed time
		}
				
		Renderer::DrawMap(renderer, gameMap);
		Renderer::DrawPlayer(renderer, player);
		SDL_RenderPresent(renderer);
	}

	//close the window and clean up
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
