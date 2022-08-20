#include "ChessField.h"
#include "Horse.h"
#include "King.h"
#include <iostream>

ChessField::ChessField()
{
	Init();
	UpdateField();
}

bool ChessField::Step(FigureId figureId, int xPos, int yPos)
{
	if (CheckOutOfRange(xPos, yPos) == false)
	{
		return false;
	}

	if (m_field[yPos][xPos] != FigureId::FigIdEmpty)
	{
		return false;
	}

	Figure* curFig = GetCurFigure();
	if (figureId == FigureId::FigIdHorse)
	{
		if (((Horse*)curFig)->CanMoveToPosition(xPos, yPos) == false)
		{
			return false;
		}
	}
	else if (figureId == FigureId::FigIdKing)
	{
		if (((King*)curFig)->CanMoveToPosition(xPos, yPos) == false)
		{
			return false;
		}
	}

	curFig->SetCurrentCoordinates(xPos, yPos);
	UpdateField();
	UpdateFigure();
	return true;
}

bool ChessField::Step(int fromX, int fromY, int toX, int toY)
{
	if (CheckOutOfRange(toX, toY) == false)
	{
		return false;
	}

	if (m_field[toX][toY] != FigureId::FigIdEmpty)
	{
		return false;
	}
	return true;
}

void ChessField::ShowBoard()
{
	std::cout << "\n";
	std::cout << "  ";
	for (int i = 0; i < FieldCols; i++)
	{
		std::cout << "  " << i << "  ";
	}
	std::cout << "  -> X";
	std::cout << "\n  -----------------------------------------\n";
	for (int i = 0; i < FieldRows; i++)
	{
		std::cout << i << " |";
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
			std::cout << "|";
		}
		std::cout << "\n  -----------------------------------------";
		std::cout << "\n";
	}
	std::cout << "Y\n";
}

Color ChessField::GetPlayerColor() const
{
	return GetCurFigure()->GetColor();
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

bool ChessField::CheckOutOfRange(int xPos, int yPos) const
{
	if (xPos < 0 || xPos >= FieldCols) // check cols
	{
		return false;
	}

	if (yPos < 0 || yPos >= FieldRows) // check rows
	{
		return false;
	}
	return true;
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

void ChessField::Init()
{
	m_figures = new Figure * [m_size];
	m_figures[0] = new Horse(5, 3, Color::ColWhite);
	m_figures[1] = new King(2, 1, Color::ColBlack);
}

void ChessField::UpdateFigure()
{
	m_curFigureId++;
	m_curFigureId %= m_size;
}

Figure* ChessField::GetCurFigure() const
{
	return m_figures[m_curFigureId];
}

void ChessField::UpdateField()
{
	for (int row = 0; row < FieldRows; row++)
	{
		for (int col = 0; col < FieldCols; col++)
		{
			m_field[row][col] = FigureId::FigIdEmpty;
		}
	}
	for (int i = 0; i < m_size; i++)
	{
		int x = m_figures[i]->GetX();
		int y = m_figures[i]->GetY();
		m_field[y][x] = m_figures[i]->GetFigureId();
	}
}
