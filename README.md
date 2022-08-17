"Реализовать игру шахматы. В игре у нас будут участвовать только 1 конь и король. 
Игроки делают ходы последовательно.
У нас будет базовый класс :
class Figure
{ 
    Figure(xPos, yPos) - устанавливает фигуру в начальное положение
    Color GetColor()  // Black и White
    GetFigureId() - у каждой фигуры есть идентификатор, тип не важен, главное чтобы он был 
    уникальным
    SetCurrentCoordinates(xPos, yPos)
};

class King  // наследуется от Figure 
{
    bool CanMoveToPosition(xPos, yPos) - возвращает true если фигура смогла так перейти 
};

class Horse  // наследуется от Figure 
{
    bool CanMoveToPosition(xPos, yPos) - возвращает true если фигура смогла так перейти 
};

class СhessField {
  СhessField() - расставляет фигуры в начальные позиции позиции
  bool Step(figureId, xPos, yPos) - делает шаг фигурой на определенную позицию. 
  если фигура смогла так перейти - возвращает true иначе не перемещает и возвращает false
  ShowBoard() - выводит на экран доску с фигурами
};"