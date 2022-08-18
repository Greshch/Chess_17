#pragma once
#include "Figure.h"

class Horse :
    public Figure
{
public:
    Horse();
    Horse(int xPos, int yPos);
    Horse(int xPos, int yPos, Color color);
    bool CanMoveToPosition(int xPos, int yPos);
    ~Horse();
};

