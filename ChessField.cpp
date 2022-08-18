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
				std::cout << "    ";
			}
			else
			{
				Color color = GetColor(j, i);
				if (color == Color::ColWhite)
				{
					std::cout << "W";
				}
				else if (color == Color::ColBlack)
				{
					std::cout << "B";
				}
				else
				{
					std::cout << "?";
				}
				std::cout << ":";
				
				if (m_field[i][j] == FigureId::FigIdHorse)
				{
					std::cout << "Hr";
				}
				else if (m_field[i][j] == FigureId::FigIdKing)
				{
					std::cout << "Kg";
				}
			}
		}
		std::cout << "\n";
	}
}

Color ChessField::GetColor(int xPos, int yPos) const
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_figures[i]->GetX() == xPos && m_figures[i]->GetY() == yPos)
		{
			return m_figures[i]->GetColor();
		}
	}
	return Color::ColInvalid;
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
