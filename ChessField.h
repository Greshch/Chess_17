#pragma once
#include "Figure.h"

class ChessField
{
public:
	ChessField(); //-расставляет фигуры в начальные позиции позиции
	bool Step(FigureId figureId, int xPos, int yPos); 
	/*-делает шаг фигурой на определенную позицию.
	  если фигура смогла так перейти - возвращает true иначе не перемещает 
	  и возвращает false
	*/
	bool Step(int fromX, int fromY, int toX, int toY);
	void ShowBoard(); //- выводит на экран доску с фигурами
	Color GetPlayerColor() const;
	Figure* GetCurFigure() const;
	~ChessField();

private:
	static const int FieldRows = 8;
	static const int FieldCols = 8;
	int m_field[FieldRows][FieldCols];
	int m_size = 2;
	Figure** m_figures;
	int m_curFigureId = 0;
	

private: 
	void Init();
	void UpdateField();
	void UpdateFigure();
	Color GetColor(int xPos, int yPos) const;
	bool CheckOutOfRange(int xPos, int yPos) const;
};

