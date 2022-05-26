#include "Coord.h"
Coord::Coord(int x, int y) : x(x), y(y) {
}

int Coord::getX() const
{
	return this->x;
}

void Coord::setX(int x)
{
	this->x = x;
}

int Coord::getY() const
{
	return this->y;
}

void Coord::setY(int y)
{
	this->y = y;
}
