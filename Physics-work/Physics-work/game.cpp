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
		wind = 0;
	}
	if (KeyState[SDL_SCANCODE_1])
	{
		wind = 1;
	}
	if (KeyState[SDL_SCANCODE_2])
	{
		wind = 2;
	}
	if (KeyState[SDL_SCANCODE_3])
	{
		wind = 3;
	}
	if (KeyState[SDL_SCANCODE_4])
	{
		wind = 4;
	}

	if (KeyState[SDL_SCANCODE_ESCAPE])
	{
		running = false;
	}
}

void game::Update() 
{
	std::cout << itemAmount << std::endl;
	if (itemAmount != 300) {
		
		item_test[itemAmount] = new item(renderer, rand() % 1000 + (-2000), 2);
		itemAmount++;
	}
	for (int i = 0; i < itemAmount; i++)
	{
		item_test[i]->MoveItem(wind);
		if (item_test[i]->yPos > 690) 
		{
			delete item_test[i];
			item_test[i] = new item(renderer, rand() % 1000 + (-200),rand()%5+2);
		}
	}
}


void game::Render()
{
	SDL_RenderClear(renderer);
	for (int i = 0; i < itemAmount; i++)
	{
		item_test[i]->RenderItem();
	}
	SDL_RenderPresent(renderer);
}




void game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}