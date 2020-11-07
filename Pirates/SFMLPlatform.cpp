#include "SFMLPlatform.h"
#include <iostream>

using std::endl;

SFMLPlatform::SFMLPlatform(size_t worldSizeX, size_t worldSizeY)
    : window(sf::VideoMode(worldSizeX * SPRITE_SIZE, worldSizeY * SPRITE_SIZE), "Pirate game")
{}

void SFMLPlatform::init()
{
    window.setFramerateLimit(60);

    if (!textureTerrain.loadFromFile("sprites/terrain.png")) {
        std::cerr << "Can't load texture" << endl;
        return;
    }

	grassSprite.setTexture(textureTerrain);
	grassSprite.setTextureRect(sf::IntRect(SPRITE_SIZE * 0, SPRITE_SIZE * 0, SPRITE_SIZE, SPRITE_SIZE));

	sandSprite.setTexture(textureTerrain);
	sandSprite.setTextureRect(sf::IntRect(SPRITE_SIZE * 1, SPRITE_SIZE * 0, SPRITE_SIZE, SPRITE_SIZE));

	stoneSprite.setTexture(textureTerrain);
	stoneSprite.setTextureRect(sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 0, SPRITE_SIZE, SPRITE_SIZE));

	pathSprite.setTexture(textureTerrain);
	pathSprite.setTextureRect(sf::IntRect(SPRITE_SIZE * 3, SPRITE_SIZE * 0, SPRITE_SIZE, SPRITE_SIZE));

	pirateSprite.setTexture(textureTerrain);
	pirateSprite.setTextureRect(sf::IntRect(SPRITE_SIZE * 0, SPRITE_SIZE * 1, SPRITE_SIZE, SPRITE_SIZE));

	treasureSprite.setTexture(textureTerrain);
	treasureSprite.setTextureRect(sf::IntRect(SPRITE_SIZE * 1, SPRITE_SIZE * 1, SPRITE_SIZE, SPRITE_SIZE));

	enemySprite.setTexture(textureTerrain);
	enemySprite.setTextureRect(sf::IntRect(SPRITE_SIZE * 2, SPRITE_SIZE * 1, SPRITE_SIZE, SPRITE_SIZE));
}

void SFMLPlatform::drawSprite(char spriteChar, int row, int col)
{
	int x = col * SPRITE_SIZE;
	int y = row * SPRITE_SIZE;

	sf::Sprite* sprite = spriteMap[spriteChar];
	sprite->setPosition(x, y);
	window.draw(*sprite);
}

void SFMLPlatform::drawRow(const char* string, int row, int col)
{
	const char* c = string;
	while (*c != '\0') {
		drawSprite(*c, row, col++);
		++c;
	}
}

Input SFMLPlatform::update()
{
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			window.close();
	}

	Input input = Input::NONE;

	bool tmpKeyPressed = false;
	for (auto pair : inputMap)
	{
		auto key = pair.first;
		if ((tmpKeyPressed |= sf::Keyboard::isKeyPressed(key)) && !keyPressed) {
			input = pair.second;
			keyPressed = true;
		}
	}

	keyPressed = tmpKeyPressed;

	return input;
}
