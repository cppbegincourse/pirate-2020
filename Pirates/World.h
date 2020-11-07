#pragma once
#include <vector>
#include <string>
#include "SFMLPlatform.h"
#include "Pirate.h"
#include "Treasure.h"
#include "Enemy.h"

typedef std::vector<std::string> Level;
//class SFMLPlatform;

constexpr char PIRATE_CHAR = '@';
constexpr char EMPTY_PLACE_CHAR = ' ';
constexpr char WALL_CHAR = '*';
constexpr char TREASURE_CHAR = 'x';
constexpr char ENEMY_CHAR = '&';

class World
{
private:
    size_t sizeX;
    size_t sizeY;

    Level gameField;

    Pirate pirate;
    Treasure treasure;
    Enemy enemy;
private:
    void initGameField();

public:
    bool treasureFound = false;
    bool pirateDied = false;

public:
    World();
    void update(Input input, int dt);
    void draw(SFMLPlatform &platform);
    void drawField(SFMLPlatform& platform);
    size_t getSizeX() { return sizeX; };
    size_t getSizeY() { return sizeY; };

    void clearGameFieldElement(int x, int y);
    void setGameFieldElement(int x, int y, char newChar);

    bool isWall(int x, int y);
    bool isTreasure(int x, int y);
    bool checkCollision(Actor& actor, int x, int y);
};

