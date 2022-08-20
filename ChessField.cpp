#include "ChessField.h"
#include "Horse.h"
#include "King.h"
#include <iostream>

ChessField::ChessField()
{
	Init();
	UpdateField();
}

bool ChessField::Step(int toX, int toY)
{
	if (m_fig->GetFigureId() == FigureId::FigIdHorse)
	{
		if (((Horse*)m_fig)->CanMoveToPosition(toX, toY) == false)
		{
			return false;
		}
	}
	else if (m_fig->GetFigureId() == FigureId::FigIdKing)
	{
		if (((King*)m_fig)->CanMoveToPosition(toX, toY) == false)
		{
			return false;
		}
	}
	m_fig->SetCurrentCoordinates(toX, toY);
	UpdateField();
	UpdatePlayer();
	m_fig = nullptr;
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

Color ChessField::GetPlayer() const
{
	return m_player;
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


Figure* ChessField::GetFigure(int xPos, int yPos)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_figures[i]->GetX() == xPos && m_figures[i]->GetY() == yPos)
		{
			return m_figures[i];
		}
	}
	return nullptr;
}

bool ChessField::ReadCurentFigure(int xPos, int yPos)
{
	Figure* cur = GetFigure(xPos, yPos);
	if (cur == nullptr) // Check existing figure by coords
	{
		return false;
	}
	
	if (cur->GetColor() != m_player) // check color figure
	{
		return false;
	}
	m_fig = cur; // Cur figures was choosen!
	return true;
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

void ChessField::UpdatePlayer()
{
	m_player = (m_player == Color::ColBlack) ? Color::ColWhite : Color::ColBlack;
}
