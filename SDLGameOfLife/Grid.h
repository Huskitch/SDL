#pragma once
#include "Window.h"
#include "Utils.h"
#include <vector>
#include <iostream>

class Grid
{
public:
	Grid();
	~Grid();

	void Update();
	void Draw(Window& window);
	void HandleInputs(SDL_Event* e);

	void ProgressStage();
	void PlaceCell(Vector2 position);
	int GetAdjacentCells(Vector2 position);

	void SetPosition(int x, int y);
	void SetScale(int x, int y);
	void SetGridWidth(int width);


private:
	Vector2 mousePosition;

	Vector2 scale;
	Vector2 position;

	int gridWidth;

	std::vector<std::vector<bool>> gridCells;
};

