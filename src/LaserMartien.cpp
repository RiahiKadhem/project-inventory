#include "LaserMartien.h"
#include <iostream>
#include "UIKit.h"


void LaserMartien::effacer()
{
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << " ";
}

void LaserMartien::afficher()
{
	UIKit::color(12);
	Laser::afficher();
	UIKit::color(13);
}

LaserMartien::LaserMartien(unsigned short Colour, Coord c, TypeLaser typeLaser) : Laser(c, typeLaser)
{
}

LaserMartien::~LaserMartien()
{
}
