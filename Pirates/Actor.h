#pragma once
#include "Input.h"
#include "Point.h"

enum class DirectionY {
	UP = -1,
	NONE = 0,
	DOWN = 1,
};

enum class DirectionX {
	LEFT = -1,
	NONE = 0,
	RIGHT = 1
};

class Actor
{
private:
	int x = 0;
	int y = 0;

public:
	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; };
	void setCoords(int x, int y);

	int getX() { return x; }
	int getY() { return y; }

	//virtual void update(Input input) = 0;
	virtual Point move(DirectionX dirX, DirectionY dirY);

	Actor() : x(0), y(0) {}
	Actor(int x, int y) : x(x), y(y) {}
};

