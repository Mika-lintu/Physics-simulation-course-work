//MIKA LINTULA
#include "game.h"

game *Game = nullptr;
int main(int argc, char *argv[])
{
	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last = 0;
	

	Game = new game();
	Game->init("The Game");

	while (Game->Running())
	{
		last = now;
		now = SDL_GetPerformanceCounter();
		Game->deltaTime = (double)((now - last) * 1000 / SDL_GetPerformanceFrequency());
		frameStart = SDL_GetTicks();
		Game->HandleEvents();
		Game->Update();
		Game->Render();
		
		frameTime = SDL_GetTicks() - frameStart;
		std::cout << Game->deltaTime<< std::endl;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	Game->Clean();

	return 0;
}