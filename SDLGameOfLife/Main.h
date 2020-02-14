#pragma once
#include "SDL.h"
#include "Window.h"
#include "Grid.h"

class Main
{
public:
	Main();
	~Main();

	void Update();
	void Draw(Window& window);
	void HandleInputs();

private:
	Grid grid;
};

