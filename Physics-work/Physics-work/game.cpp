#include "game.h"

game::game()
{
}


game::~game()
{
}

void game::init(const char* title) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_height, window_width, SDL_WINDOW_SHOWN);

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 96, 96, 96, 0);
		}
		srand(time(NULL));
		running = true;
	}

	itemAmount = 0;
	wind = 2;
}


void game::HandleEvents()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent));
	const Uint8 *KeyState = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&sdlEvent);

	if (KeyState[SDL_SCANCODE_LEFT]) 
	{
		wind++;
	}
	if (KeyState[SDL_SCANCODE_0])
	{
		wind = -10;
	}
	if (KeyState[SDL_SCANCODE_1])
	{
		wind = -5;
	}
	if (KeyState[SDL_SCANCODE_2])
	{
		wind = 0;
	}
	if (KeyState[SDL_SCANCODE_3])
	{
		wind = 5;
	}
	if (KeyState[SDL_SCANCODE_4])
	{
		wind = 10;
	}

	if (KeyState[SDL_SCANCODE_ESCAPE])
	{
		running = false;
	}
}

void game::Update() 
{
	//std::cout << deltaTime << std::endl;
	if (itemAmount != 300) {
		
		itemArray[itemAmount] = new item(renderer);
		itemAmount++;
	}
	for (int i = 0; i < itemAmount; i++)
	{
		itemArray[i]->MoveItem(wind);
		if (itemArray[i]->pos.y > 690) 
		{
			delete itemArray[i];
			itemArray[i] = new item(renderer);
		}
	}
}


void game::Render()
{
	SDL_RenderClear(renderer);
	for (int i = 0; i < itemAmount; i++)
	{
		itemArray[i]->RenderItem();
	}
	SDL_RenderPresent(renderer);
}




void game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}