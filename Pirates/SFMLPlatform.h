#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>

#include "Input.h"

constexpr int SPRITE_SIZE = 64;

class SFMLPlatform
{
public:
	SFMLPlatform(size_t worldSizeX, size_t worldSizeY);
	void init();
	void drawSprite(char spriteChar, int row, int col);
	void drawRow(const char* string, int row, int col);

	Input update();

	void endDraw() { window.display(); };
private:
	std::map<sf::Keyboard::Key, Input> inputMap{ {sf::Keyboard::Up, Input::UP}, {sf::Keyboard::W, Input::UP}, {sf::Keyboard::Down, Input::DOWN}, {sf::Keyboard::S, Input::DOWN}, {sf::Keyboard::Left, Input::LEFT}, {sf::Keyboard::A, Input::LEFT}, {sf::Keyboard::D, Input::RIGHT}, {sf::Keyboard::Right, Input::RIGHT}, {sf::Keyboard::Q, Input::EXIT}, {sf::Keyboard::P, Input::SHOW_PATH} };
	std::map<char, sf::Sprite*> spriteMap{ {'*', &stoneSprite}, {' ', &grassSprite}, {'~', &sandSprite}, {'.', &pathSprite}, {'@', &pirateSprite}, {'&', &enemySprite}, {'x', &treasureSprite} };
	sf::RenderWindow window;
	sf::Texture textureTerrain;

	sf::Sprite sandSprite;
	sf::Sprite stoneSprite;
	sf::Sprite grassSprite;
	sf::Sprite pathSprite;
	sf::Sprite enemySprite;
	sf::Sprite pirateSprite;
	sf::Sprite treasureSprite;

	bool keyPressed = false;
};

