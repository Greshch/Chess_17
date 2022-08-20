#include "ChessField.h"
#include <iostream>

int main()
{
	const int steps = 3;
	ChessField field;
	field.ShowBoard();
	for (int i = 0; i < steps;)
	{
		
		int fromX = 0;
		int fromY = 0;
		std::cout << "Chose " << (field.GetPlayer() == Color::ColBlack ? " Black " : "White ")
			<< "figure Input(X, Y) : ";
		std::cin >> fromX >> fromY;
		if (field.ReadCurentFigure(fromX, fromY) == false)
		{
			std::cerr << "You've just misschosen figure... Let's try it again!!\n";
			continue;
		}

		int toX = 0;
		int toY = 0;
		std::cout << "Input to coords " << "(X, Y) : ";
		std::cin >> toX >> toY;

		if (!field.Step(toX, toY))
		{
			std::cerr << "Incorrect input\n";
		}
		else
		{
			field.ShowBoard();
			++i;
		}
	}

	return 0;
}

