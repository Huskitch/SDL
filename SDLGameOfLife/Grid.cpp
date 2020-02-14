#include "Grid.h"

Grid::Grid()
{

}

Grid::~Grid()
{

}

void Grid::Update()
{
	SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
}

void Grid::Draw(Window& window)
{
	for (int x = 0; x < scale.x; x++)
	{
		for (int y = 0; y < scale.y; y++)
		{
			SDL_SetRenderDrawColor(window.GetRenderer(), 255, 255, 255, 255);
			SDL_RenderDrawLine(window.GetRenderer(), position.x + x * gridWidth, position.x + y * gridWidth, position.x, position.y + y * gridWidth);
			SDL_RenderDrawLine(window.GetRenderer(), position.x + x * gridWidth, position.y + y * gridWidth, position.x + x * gridWidth, position.y + y);

			if (gridCells[x][y])
			{
				SDL_Rect cell = { position.x + x * gridWidth, position.y + y * gridWidth, gridWidth, gridWidth };
				SDL_RenderFillRect(window.GetRenderer(), &cell);
			}
		}
	}
}

void Grid::HandleInputs(SDL_Event* e)
{
	switch (e->type)
	{
	case SDL_KEYDOWN:
		ProgressStage();
		break;

	case SDL_MOUSEBUTTONDOWN:
		Vector2 currentCell;
		currentCell.x = ((mousePosition.x + position.x) / gridWidth) - 1;
		currentCell.y = ((mousePosition.y + position.y) / gridWidth) - 1;

		PlaceCell(currentCell);
		std::cout << GetAdjacentCells(currentCell) << std::endl;
		break;
	}
}

void Grid::ProgressStage()
{
	for (int x = 0; x < scale.x; x++)
	{
		for (int y = 0; y < scale.y; y++)
		{
			if (gridCells[x][y] == true && GetAdjacentCells(Vector2(x, y)) <= 1)
				gridCells[x][y] = false;

			if (gridCells[x][y] == true && GetAdjacentCells(Vector2(x, y)) >= 4)
				gridCells[x][y] = false;

			if (gridCells[x][y] == false && GetAdjacentCells(Vector2(x, y)) == 3)
				gridCells[x][y] = true;
		}
	}
}

void Grid::PlaceCell(Vector2 position)
{
	gridCells[position.x][position.y] = true;
}

int Grid::GetAdjacentCells(Vector2 position)
{
	int cellCount = 0;

	for (int xOffset = -1; xOffset <= 1; xOffset++)
	{
		for (int yOffset = -1; yOffset <= 1; yOffset++)
		{
			int xPos = xOffset + position.x;
			int yPos = yOffset + position.y;

			if (xPos > scale.x - 1 || xPos < 0) break;
			if (yPos > scale.y - 1 || yPos < 0) continue;
			if (xOffset == 0 && yOffset == 0) continue;

			if (gridCells[xPos][yPos]) cellCount++;
		}
	}

	return cellCount;
}

void Grid::SetPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}

void Grid::SetScale(int x, int y)
{
	this->scale.x = x;
	this->scale.y = y;

	gridCells = std::vector<std::vector<bool>>(scale.x, std::vector<bool>(scale.y, false));
}

void Grid::SetGridWidth(int width)
{
	this->gridWidth = width;
}

