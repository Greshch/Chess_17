#include "ChessField.h"
#include <iostream>

void ReadStep(int& x, int& y, Color color);

int main()
{
	int X = 0;
	int Y = 0;
	const int steps = 3;
	ChessField field;
	for (int i = 0; i < steps;)
	{
		field.ShowBoard();
		//ReadStep(X, Y, );
		/*Figure* cur = field.GetCurFigure();
		FigureId curID = cur->GetFigureId();
		if (!field.Step(curID, X, Y))
		{
			std::cerr << "Incorrect input\n";
		}
		else
		{
			++i;
		}*/
	}
	field.ShowBoard();

	return 0;
}

void ReadStep(int& x, int& y, Color color)
{
	if (color == Color::ColBlack)
	{
		std::cout << "Black player is turning\n";
	}
	else
	{
		std::cout << "White player is turning\n";
	}
	std::cout << "(X, Y): ";
	std::cin >> x >> y;
}
