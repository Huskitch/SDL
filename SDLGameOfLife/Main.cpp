#include "Main.h"

Main::Main()
{
	grid.SetScale(64, 36);
	grid.SetPosition(10, 10);
	grid.SetGridWidth(20);
}

Main::~Main()
{

}

void Main::Update()
{
	grid.Update();
}

void Main::Draw(Window& window)
{
	SDL_SetRenderDrawColor(window.GetRenderer(), 0, 0, 0, 255);
	SDL_RenderClear(window.GetRenderer());

	grid.Draw(window);

	SDL_RenderPresent(window.GetRenderer());
}

void Main::HandleInputs()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		grid.HandleInputs(&e);
	}
}
