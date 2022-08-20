#include "King.h"
#include <cmath>

King::King() : Figure()
{
    m_figureId = FigureId::FigIdKing;
}

King::King(int posX, int posY) : Figure(posX, posY)
{
    m_figureId = FigureId::FigIdKing;
}

King::King(int xPos, int yPos, Color color) : Figure(xPos, yPos, color)
{
    m_figureId = FigureId::FigIdKing;
}

bool King::CanMoveToPosition(int xPos, int yPos)
{
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
