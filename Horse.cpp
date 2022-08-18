#include "Horse.h"
#include <cmath>

Horse::Horse() : Figure()
{
    m_figureId = FigureId::FigIdHorse;
}

Horse::Horse(int xPos, int yPos) : Figure(xPos, yPos)
{
    m_figureId = FigureId::FigIdHorse;
}

bool Horse::CanMoveToPosition(int xPos, int yPos)
{
    if (xPos < 0 || xPos >= FieldCols) // check cols
    {
        return false;
    }

    if (yPos < 0 || yPos >= FieldRows) // check rows
    {
        return false;
    }

    int dx = abs(m_xPos - xPos);
    int dy = abs(m_yPos - yPos);
    int const litleStep = 1;
    int const bigStep = 2;

    if (dx != litleStep && dx != bigStep)
    {
        return false;
    }

    if (dy != litleStep && dy != bigStep)
    {
        return false;
    }

    return true;
}

Horse::~Horse()
{
}
