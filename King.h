#pragma once
#include "Figure.h"

class King :
    public Figure
{
public:
    bool CanMoveToPosition(int xPos, int yPos);
};

