#include <iostream>
#include "Window.h"
#include "Main.h"

int main(int argc, char* argv[])
{
	Window window("Game of Life", 1280, 720);
	window.Init();

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	Main main;

	while (true)
	{
		main.Update();
		main.Draw(window);
		main.HandleInputs();
	}

	SDL_DestroyWindow(window.GetWindow());
	SDL_Quit();

	return 0;
}