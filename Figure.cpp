#include "Figure.h"

Figure::Figure() : Figure(0, 0)
{
}

Figure::Figure(int xPos, int yPos) : m_xPos(xPos),
                                     m_yPos(yPos)
{
}

Color Figure::GetColor() const
{
    return m_color;
}

FigureId Figure::GetFigureId() const
{
    return m_figureId;
}

Figure::~Figure()
{
}
