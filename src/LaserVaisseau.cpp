#include "LaserVaisseau.h"
#include "UIKit.h"
#include <iostream>



void LaserVaisseau::effacer()
{
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << " ";
}

void LaserVaisseau::afficher()
{
	UIKit::color(10);
	Laser::afficher();
	UIKit::color(11);
}

LaserVaisseau::LaserVaisseau(unsigned short Colour, Coord c, TypeLaser typeLaser) : Laser(c, typeLaser)
{
}

LaserVaisseau::~LaserVaisseau()
{
}
