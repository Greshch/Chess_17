#pragma once
#include "Figure.h"

class ChessField
{
public:
	ChessField(); //-����������� ������ � ��������� ������� �������
	bool Step(FigureId figureId,int xPos, int yPos); 
	/*-������ ��� ������� �� ������������ �������.
	  ���� ������ ������ ��� ������� - ���������� true ����� �� ���������� 
	  � ���������� false
	  */
	void ShowBoard(); //- ������� �� ����� ����� � ��������
	~ChessField();

private:
	int m_field[FieldRows][FieldCols] = { 0 };
	int m_size = 2;
	Figure** m_figures;
};

