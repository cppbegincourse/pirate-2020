#include "Enemy.h"
#include "World.h"

void Enemy::update(World &world, int dt)
{
	timer -= dt;
	if (timer <= 0)
	{
		// move
		Point p = move(DirectionX::RIGHT, DirectionY::NONE);
		if (!world.isWall(p.x, p.y))
		{
			setCoords(p.x, p.y);
		}
		timer = MOVE_DELAY;
	}
}
