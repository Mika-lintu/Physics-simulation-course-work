#include "item.h"
#include <iostream>

SDL_Rect r;
SDL_Renderer *rend;

item::item(SDL_Renderer *ren, int num, int size)
{
	yPos = 0;
	xPos = num;
	yVel = 4;
	
	rend = ren;
	r.w = size;
	r.h = size;

}

item::~item()
{
}

void item::RenderItem() 
{
		r.x = xPos;
		r.y = yPos;
		SDL_SetRenderDrawColor(rend, 78, 110, 216, 0);
		SDL_RenderFillRect(rend, &r);
		SDL_SetRenderDrawColor(rend, 55, 55, 55, 0);
}

void item::MoveItem(int wind) 
{
	if (yPos < 700)
	{
		switch (wind)
		{
		case 0:
			yPos += yVel;
			xPos -= yVel - 1;
			break;
		case 1:
			yPos += yVel;
			xPos -= yVel - 3;
			break;
		case 2:
			yPos+=yVel;
			break;
		case 3:
			yPos += yVel;
			xPos += yVel - 3;
			break;
		case 4:
			yPos += yVel;
			xPos += yVel - 1;
			break;
		default:
			break;
		}
	}    
}
