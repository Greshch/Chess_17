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
	void ShowBoard(); //- выводит на экран доску с фигурами
	Color GetColor(int xPos, int yPos) const;
	~ChessField();

private:
	int m_field[FieldRows][FieldCols];
	int m_size = 2;
	Figure** m_figures;
	int m_curFigureId = 0;
	

private: 
	void Init();
	void UpdateField();
	void UpdateFigure();
	Figure* GetCurFigure() const;
};

