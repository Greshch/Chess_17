#include "ChessField.h"
#include <iostream>

ChessField::ChessField()
{
}

void ChessField::ShowBoard()
{
	for (int i = 0; i < FieldRows; i++)
	{
		for (int j = 0; j < FieldCols; j++)
		{
			if (m_field[i][j] == FigureId::Empty)
			{

			}
			else if (m_field[i][j] == FigureId::Horse)
			{

			}
			else if (m_field[i][j] == FigureId::King)
			{

			}
		}
		std::cout << "\n";
	}
}
