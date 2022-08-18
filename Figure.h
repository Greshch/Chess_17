#pragma once

#include "Types_n_Consts.h"

class Figure
{
public:
    Figure();
    Figure(int xPos, int yPos); //-������������� ������ � ��������� ���������
    Figure(int xPos, int yPos, Color color);
    Color GetColor() const;  // Black � White
    FigureId GetFigureId() const; /*-� ������ ������ ���� �������������, ��� �� �����, ������� 
                            ����� �� ��� ����������*/
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

