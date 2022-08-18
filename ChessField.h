#pragma once
#include "Figure.h"
#include "Horse.h"
#include "King.h"

int const FieldRows = 8;
int const FieldCols = 8;

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

private:
	int m_field[FieldRows][FieldCols] = { 0 };
};

