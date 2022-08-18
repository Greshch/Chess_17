#pragma once
enum Color {
    Black,
    White
};

enum FigureId {
    King = -1,
    Horse = 1,
    Empty = 0
};

class Figure
{
public:
    Figure();
    Figure(int xPos, int yPos); //-������������� ������ � ��������� ���������
    Color GetColor() const;  // Black � White
    FigureId GetFigureId() const; /*-� ������ ������ ���� �������������, ��� �� �����, ������� 
                            ����� �� ��� ����������*/
    void SetCurrentCoordinates(int xPos, int yPos);

private:
    int m_xPos = 0;
    int m_yPos = 0;
    Color m_color = Color::Black;
    FigureId m_figureId = FigureId::King;
};

