#pragma once
#include "Figure.h"

class ChessField
{
public:
	ChessField(); //-����������� ������ � ��������� ������� �������
	bool Step(FigureId figureId, int xPos, int yPos); 
	/*-������ ��� ������� �� ������������ �������.
	  ���� ������ ������ ��� ������� - ���������� true ����� �� ���������� 
	  � ���������� false
	*/
	bool Step(int fromX, int fromY, int toX, int toY);
	void ShowBoard(); //- ������� �� ����� ����� � ��������
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

