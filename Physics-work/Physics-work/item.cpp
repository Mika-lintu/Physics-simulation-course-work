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

void item::MoveItem(int wind, float dt) 
{

	if (pos.y < 700)
	{
		float delta = 0.01;
		dt = delta;

		//glm::vec2 windVel = glm::vec2(1, 0);
		float dragwind;
		area = 3.14*d*d / 4;
		//dragForce = ((density*C*area)/2)*(vel.y*vel.y);
	

		dragwind = ((density*C*area) / 2)*(wind*wind);

		glm::vec2 a = g / dt;

		//vel = vel +dt*a;

		//a.y = dragForce / m;
		a.x = dragwind / m;
		vel = vel + dt*a;
		vel.x = a.x;
		pos = pos + dt*vel;
	}    
}

void item::Drag() 
{
	
}
