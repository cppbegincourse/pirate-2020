#pragma once
#include "Actor.h"
constexpr int MOVE_DELAY = 500;

class World;

class Enemy :
    public Actor
{
public:
    Enemy() : timer(MOVE_DELAY) {}
    void update(World& world, int dt);

private:
    int timer;
};

