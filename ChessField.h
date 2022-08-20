#pragma once
#include "Figure.h"

class ChessField
{
public:
	ChessField(); //-расставляет фигуры в начальные позиции позиции
	bool Step(int toX, int toY);
	void ShowBoard(); //- выводит на экран доску с фигурами
	Color GetPlayer() const;
	Figure* GetFigure(int xPos, int yPos);
	bool ReadCurentFigure(int xPos, int yPos);
	~ChessField();

private:
	static const int FieldRows = 8;
	static const int FieldCols = 8;
	int m_field[FieldRows][FieldCols];
	int m_size = 2;
	Figure** m_figures;
	Color m_player = Color::ColWhite;
	Figure* m_fig = nullptr;
	

private: 
	void Init();
	void UpdateField();
	void UpdatePlayer();
	Color GetColor(int xPos, int yPos) const;
	bool CheckOutOfRange(int xPos, int yPos) const;
};

