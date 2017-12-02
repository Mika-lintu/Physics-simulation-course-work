#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>


#include <glm.hpp>

#include <SDL.h>

#include "item.h"


#define window_width 680
#define window_height 480
const int TOTAL = 300;
class game
{
public:

	game();
	virtual ~game();

	int itemAmount;
	int wind;

	void init(const char* title);

	void HandleEvents();
	void Update();
	bool Running() { return running; }
	void Render();
	void Clean();

	
private:
	bool running = false;

	item* item_test[TOTAL];
	item *item1;

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Rect rect;
};
