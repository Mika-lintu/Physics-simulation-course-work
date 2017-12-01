//MIKA LINTULA

#include <iostream>
#include <SDL.h>


#define window_width 680
#define window_height 480

SDL_Window *window;
SDL_Renderer *renderer;

int main(int argc, char *argv[]) 
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Physics_simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_height, window_width, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 20, 100, 55);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
	return 0;
}