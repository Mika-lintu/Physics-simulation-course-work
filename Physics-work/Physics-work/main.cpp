//MIKA LINTULA
#include "game.h"

game *Game = nullptr;
int main(int argc, char *argv[])
{
	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	Game = new game();
	Game->init("The Game");

	while (Game->Running())
	{
		frameStart = SDL_GetTicks();
		Game->HandleEvents();
		Game->Update();
		Game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	Game->Clean();

	return 0;
}