#include "King.h"
#include <cmath>

King::King() : Figure()
{
    m_figureId = FigureId::FigIdKing;
}

King::King(int posX, int posY) : Figure(posX, posY)
{
    m_figureId = FigureId::FigIdHorse;
}

bool King::CanMoveToPosition(int xPos, int yPos)
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
    int const litleStep = 0;
    int const bigStep = 1;

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

King::~King()
{
}
