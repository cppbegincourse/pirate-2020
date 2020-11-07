#pragma once
#include "Actor.h"
class Pirate :
    public Actor
{
public:
    void draw();
    Point update(Input input);
};

