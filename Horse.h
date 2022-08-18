#pragma once
#include "Figure.h"
class Horse :
    public Figure
{
public:
    bool CanMoveToPosition(int xPos, int yPos);
};

