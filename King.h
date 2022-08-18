#pragma once
#include "Figure.h"

class King :
    public Figure
{
public:
    King();
    King(int posX, int posY);
    King(int xPos, int yPos, Color color);
    bool CanMoveToPosition(int xPos, int yPos);
    ~King();
};

