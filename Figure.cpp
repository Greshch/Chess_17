#include "Figure.h"

Figure::Figure() : Figure(0, 0)
{
}

Figure::Figure(int xPos, int yPos) : m_xPos(xPos),
                                     m_yPos(yPos)
{
}

Figure::Figure(int xPos, int yPos, Color color) : Figure(xPos, yPos)
{
    m_color = color;
}

Color Figure::GetColor() const
{
    return m_color;
}

FigureId Figure::GetFigureId() const
{
    return m_figureId;
}

void Figure::SetCurrentCoordinates(int xPos, int yPos)
{
    m_xPos = xPos;
    m_yPos = yPos;
}

int Figure::GetX() const
{
    return m_xPos;
}

int Figure::GetY() const
{
    return m_yPos;
}

Figure::~Figure()
{
}
