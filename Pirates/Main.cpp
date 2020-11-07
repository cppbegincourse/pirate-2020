#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "SFMLPlatform.h"
#include "World.h"
#include "Input.h"

#include <chrono>


using namespace std;

constexpr int FIELD_WIDTH = 20;
constexpr int FIELD_HEIGHT = 20;

void init(SFMLPlatform& platform);
void update();

int treasureX;
int treasureY;

int pirateX = 0, pirateY = 0;

std::chrono::milliseconds elapsedTime;
std::chrono::milliseconds timer;

void init(SFMLPlatform &platform) {
    platform.init();
    timer = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now().time_since_epoch());
}

void update(World &world, SFMLPlatform &platform)
{
    bool isGameRunning = true;
    while (isGameRunning)
    {
        std::chrono::milliseconds newTime = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now().time_since_epoch());
        elapsedTime = newTime - timer;
        timer = newTime;

        Input input = platform.update();

        world.update(input, elapsedTime.count());

        world.draw(platform);

        platform.endDraw();

        if (world.treasureFound)
        {
            cout << "You win!" << endl;
            isGameRunning = false;
        }

        if (world.pirateDied)
        {
            cout << "You loose!" << endl;
            isGameRunning = false;
        }
    }
}

int main()
{
    World world;
    SFMLPlatform platform(world.getSizeX(), world.getSizeY());
    init(platform);

    update(world, platform);

    return 0;
}
