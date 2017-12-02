#include <SDL.h>
#pragma once

class item
{
public:
	item(SDL_Renderer *ren, int num, int s);
	virtual ~item();
	
	
	int mass;
	int yVel;
	int yPos;

	void MoveItem(int wind);
	void RenderItem();

private:

	int xPos;
	
	SDL_Renderer *rend;
	SDL_Rect r;	
	int lifeTime;
};

