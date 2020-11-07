#include "Pirate.h"
#include <iostream>

Point Pirate::update(Input input)
{
	Point p(0, 0);

	switch (input)
	{
	case Input::UP:
		p = move(DirectionX::NONE, DirectionY::UP);
		break;
	case Input::DOWN:
		p = move(DirectionX::NONE, DirectionY::DOWN);
		break;
	case Input::RIGHT:
		p = move(DirectionX::RIGHT, DirectionY::NONE);
		break;
	case Input::LEFT:
		p = move(DirectionX::LEFT, DirectionY::NONE);
		break;
	default:
		break;
	}

	return p;
}
