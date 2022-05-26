#pragma once
#include "Laser.h"
class LaserMartien :
	public Laser
{
protected:

	void effacer() override;
	void afficher() override;
	unsigned short Colour;

public:
	LaserMartien(unsigned short Colour, Coord c, TypeLaser typeLaser);
	~LaserMartien();
};

