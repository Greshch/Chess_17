#pragma once
#include "Figure.h"

class King :
    public Figure
{
public:
    King();
    King(int posX, int posY);
    bool CanMoveToPosition(int xPos, int yPos);
    ~King();
};

