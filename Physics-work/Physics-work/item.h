#include <SDL.h>
#pragma once

class item
{
public:
	item(SDL_Renderer *ren);
	virtual ~item();
	
	double yVel;
	double yPos;
	double size;


	void MoveItem(int wind);
	void RenderItem();

private:

	double xPos;
	double a = 9.81;
	
	SDL_Renderer *rend;
	SDL_Rect r;
};

