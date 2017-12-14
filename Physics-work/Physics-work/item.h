#include <SDL.h>
#include <glm.hpp>


#pragma once

class item
{
public:
	item(SDL_Renderer *ren);
	virtual ~item();
	
	glm::vec2 vel;
	glm::vec2 pos;	
	float size;
	float m;
	float d;

	float area;
	float C = 0.47;
	float density = 1000;
	float df;
	

	glm::vec2 windVel;
	static glm::fvec2 g;

	void MoveItem(int wind);
	void RenderItem();

private:
	
	SDL_Renderer *rend;
	SDL_Rect r;

	void Drag();

};

