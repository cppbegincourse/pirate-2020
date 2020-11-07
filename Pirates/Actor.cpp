#include "Actor.h"

void Actor::setCoords(int x, int y) {
	setX(x);
	setY(y);
}

Point Actor::move(DirectionX dirX, DirectionY dirY)
{
	return Point(x + static_cast<int>(dirX), y + static_cast<int>(dirY));
}