#include <SDL3/SDL.h>

int main(int argc, char *argv[]) {
	bool running{true};

	//create window 
	SDL_Window *window = SDL_CreateWindow("Pacman", 448, 528, SDL_WINDOW_RESIZABLE);
	
	//initialize SDL3
	SDL_Init(SDL_INIT_VIDEO);

	//check for window creation error
	if (window == NULL){
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: $s\n", SDL_GetError());
		return 1;
	}	
	
	//game loop
	while (running){
		SDL_Event event;
		
		//event loop
		while(SDL_PollEvent(&event)){
			if (event.type == SDL_EVENT_QUIT){
				running = false;
			}
		}
	}

	//close the window and clean up
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
