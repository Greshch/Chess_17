#include "Horse.h"

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
    return false;
}
