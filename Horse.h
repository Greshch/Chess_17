#pragma once
#include "Figure.h"

class Horse :
    public Figure
{
public:
    Horse();
    Horse(int xPos, int yPos);
    bool CanMoveToPosition(int xPos, int yPos);
    ~Horse();
};

