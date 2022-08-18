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
    Figure(int xPos, int yPos); //-устанавливает фигуру в начальное положение
    Color GetColor() const;  // Black и White
    FigureId GetFigureId() const; /*-у каждой фигуры есть идентификатор, тип не важен, главное 
                            чтобы он был уникальным*/
    void SetCurrentCoordinates(int xPos, int yPos);

private:
    int m_xPos = 0;
    int m_yPos = 0;
    Color m_color = Color::Black;
    FigureId m_figureId = FigureId::King;
};

