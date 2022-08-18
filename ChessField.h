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
	Color GetColor(int xPos, int yPos) const;
	~ChessField();

private:
	int m_field[FieldRows][FieldCols];
	int m_size = 2;
	Figure** m_figures;

private: 
	void Init();
	void Update();
};

