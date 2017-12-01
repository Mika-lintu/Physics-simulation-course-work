//MIKA LINTULA

#include <iostream>
#include <time.h>
#include <stdlib.h>

#include <glm.hpp>

#include <SDL.h>

#define window_width 680
#define window_height 480

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Rect rect;

void test();
void move();
int xPos = 1;
int yPos = 1;

int main(int argc, char *argv[])
{
	int running = 1;
	const int fps = 60;
	SDL_Init(SDL_INIT_EVERYTHING);

	srand(time(NULL));

	window = SDL_CreateWindow("Tweep", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_height, window_width, SDL_WINDOW_SHOWN);

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
		if (KeyState[SDL_SCANCODE_2])
		{
			test();
		}
		if (KeyState[SDL_SCANCODE_3]) {
			move();
		}
		if (KeyState[SDL_SCANCODE_ESCAPE])
		{
			running = 0;
		}
	}
	return 0;
}
void test()
{
	SDL_RenderClear(renderer);
	rect.x = xPos;
	rect.y = yPos;
	rect.w = 20;
	rect.h = 20;
	SDL_SetRenderDrawColor(renderer, 78, 110, 216, 0);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 96, 96, 96, 0);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}
void move() 
{
	for (int i = 0; i < 660; i++)
	{
		yPos++;
		test();
		SDL_Delay(20);
	}

}