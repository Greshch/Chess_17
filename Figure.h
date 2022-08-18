#pragma once

#include "Types_n_Consts.h"

class Figure
{
public:
    Figure();
    Figure(int xPos, int yPos); //-устанавливает фигуру в начальное положение
    Figure(int xPos, int yPos, Color color);
    Color GetColor() const;  // Black и White
    FigureId GetFigureId() const; /*-у каждой фигуры есть идентификатор, тип не важен, главное 
                            чтобы он был уникальным*/
    void SetCurrentCoordinates(int xPos, int yPos);

    int GetX() const;
    int GetY() const;
    virtual ~Figure();

protected:
    int m_xPos = 0;
    int m_yPos = 0;
    Color m_color = Color::ColBlack;
    FigureId m_figureId = FigureId::FigIdKing;
};

