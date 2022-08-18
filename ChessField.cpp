#include "ChessField.h"
#include "Horse.h"
#include "King.h"
#include <iostream>

ChessField::ChessField()
{
	m_figures = new Figure*[m_size];
	m_figures[0] = new King;
	m_figures[1] = new Horse;
}

void ChessField::ShowBoard()
{
	for (int i = 0; i < FieldRows; i++)
	{
		for (int j = 0; j < FieldCols; j++)
		{
			if (m_field[i][j] == FigureId::FigIdEmpty)
			{
				std::cout << "  ";
			}
			else if (m_field[i][j] == FigureId::FigIdHorse)
			{
				std::cout << "Hr";
			}
			else if (m_field[i][j] == FigureId::FigIdKing)
			{
				std::cout << "Kg";
			}
		}
		std::cout << "\n";
	}
}

ChessField::~ChessField()
{
	for (int i = 0; i < m_size; i++)
	{
		delete m_figures[i];
		m_figures[i] = nullptr;
	}
	delete[] m_figures;
	m_figures = nullptr;
}
