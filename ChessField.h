#pragma once
#include "Figure.h"

class ChessField
{
public:
	ChessField(); //-расставляет фигуры в начальные позиции позиции
	bool Step(FigureId figureId,int xPos, int yPos); 
	/*-делает шаг фигурой на определенную позицию.
	  если фигура смогла так перейти - возвращает true иначе не перемещает 
	  и возвращает false
	  */
	void ShowBoard(); //- выводит на экран доску с фигурами
	~ChessField();

private:
	int m_field[FieldRows][FieldCols] = { 0 };
	int m_size = 2;
	Figure** m_figures;
};

