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

Horse::Horse(int xPos, int yPos, Color color) : Figure(xPos, yPos, color)
{
    m_figureId = FigureId::FigIdHorse;
}

bool Horse::CanMoveToPosition(int xPos, int yPos)
{
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

    return dx != dy;
}

Horse::~Horse()
{
}
