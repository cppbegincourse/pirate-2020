#include "World.h"
#include "SFMLPlatform.h"
#include "Actor.h"
#include <string>
#include <fstream>
#include "Point.h"

using namespace std;

World::World()
{
	initGameField();
}

void World::initGameField()
{
	string line;
	ifstream lvlFileStream("level.txt");

	int row = 0;
	auto findAndSet = [&row](Actor& e, char entityChar, string& line) {
		size_t col;
		if ((col = line.find(entityChar)) != string::npos) {
			e.setCoords(col, row);
		}
	};

	if (lvlFileStream.is_open())
	{
		while (getline(lvlFileStream, line)) {
			gameField.push_back(line);
			findAndSet(pirate, PIRATE_CHAR, line);
			findAndSet(treasure, TREASURE_CHAR, line);
			findAndSet(enemy, ENEMY_CHAR, line);
			row++;
		}

		sizeY = gameField.size();
		sizeX = gameField[0].length();
	}
}

void World::draw(SFMLPlatform& platform)
{
	drawField(platform);

	// draw pirate
	// draw enemy
}

void World::drawField(SFMLPlatform& platform)
{
	int row = 0;
	for (auto& str : gameField)
	{
		platform.drawRow(str.c_str(), row, 0);
		row++;
	}
}

void World::update(Input input, int dt)
{
	Point p = pirate.update(input);

	clearGameFieldElement(enemy.getX(), enemy.getY());
	enemy.update(*this, dt);
	setGameFieldElement(enemy.getX(), enemy.getY(), ENEMY_CHAR);

	if (!isWall(p.x, p.y))
	{
		if (isTreasure(p.x, p.y))
		{
			//Win
			treasureFound = true;
		}

		if (checkCollision(enemy, p.x, p.y))
		{
			//Loose
			pirateDied = true;
		}

		clearGameFieldElement(pirate.getX(), pirate.getY());
		pirate.setCoords(p.x, p.y);
		setGameFieldElement(pirate.getX(), pirate.getY(), PIRATE_CHAR);
	}
}

bool World::checkCollision(Actor& actor, int x, int y)
{
	return actor.getX() == x && actor.getY() == y;
}

bool World::isWall(int x, int y)
{
	return gameField[y][x] == WALL_CHAR;
}

bool World::isTreasure(int x, int y)
{
	return checkCollision(treasure, x, y);
}

void World::setGameFieldElement(int x, int y, char newChar)
{
	gameField[y][x] = newChar;
}

void World::clearGameFieldElement(int x, int y)
{
	setGameFieldElement(x, y, EMPTY_PLACE_CHAR);
}