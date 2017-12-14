#include "item.h"
#include <iostream>


glm::vec2 item::g = glm::vec2(0, 9.81); 


item::item(SDL_Renderer *ren)
{
	pos.x = rand() % 1500 + (-200);
	pos.y = 0;
	rend = ren;
	size = rand()%6+2;
	m = size;
	d = size;
	r.w = d;
	r.h = d;
	
}

item::~item()
{
}


void item::RenderItem() 
{
		r.x = pos.x;
		r.y = pos.y;
		SDL_SetRenderDrawColor(rend, 0, 100, 225, 0);
		SDL_RenderFillRect(rend, &r);
		SDL_SetRenderDrawColor(rend, 55, 55, 55, 0);
}

void item::MoveItem(int wind) 
{

		float dt = 0.01;
		

		glm::vec2 windVel = glm::vec2(wind, 0);
		glm::vec2 dragwind = g-windVel;
		area = 3.14*d*d / 4;

		

		glm::fvec2 dragForce = ((density*C*area) / 2)*(dragwind);

		glm::vec2 a = dragwind / dt;

		vel =  vel+ dt*a;
		pos = pos + dt*vel;
}

void item::Drag() 
{
	
}
