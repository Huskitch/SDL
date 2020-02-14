#pragma once

struct Vector2
{
	Vector2() {};
	Vector2(int x, int y) { this->x = x, this->y = y; }

	int x;
	int y;
};