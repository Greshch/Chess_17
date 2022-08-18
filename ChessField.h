#pragma once
#include "Figure.h"
#include "Horse.h"
#include "King.h"

int const FieldRows = 8;
int const FieldCols = 8;

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

private:
	int m_field[FieldRows][FieldCols] = { 0 };
};

