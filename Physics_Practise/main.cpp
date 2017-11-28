//MIKA LINTULA 2017

#include <iostream>

//SDL
#include "SDL.h"



//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

#define window_width    680
#define window_height   480


SDL_Window *window;
SDL_Renderer *renderer;

//FUNCTIONS
void TestingDrawing();

int main(int argc, char  *argv[])
{
	int running = 1;
	const int fps = 60;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Physics_simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_height, window_width, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 20, 100, 55);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);


	while (running) 
	{

		SDL_Event sdlEvent;

		while (SDL_PollEvent(&sdlEvent));
		const Uint8 *KeyState = SDL_GetKeyboardState(NULL);

		if (KeyState[SDL_SCANCODE_1]) 
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 100, 55);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}
		if (KeyState[SDL_SCANCODE_1])
		{
			TestingDrawing();
		}

		if (KeyState[SDL_SCANCODE_ESCAPE])
		{
			running = 0;
		}
	}

	return 0;
}

void TestingDrawing() 
{

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // the rect color (solid red)
	SDL_Rect rect(0, 0, 100, 50); // the rectangle
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}