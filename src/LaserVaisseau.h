#pragma once
#include "Laser.h"
class LaserVaisseau :
	public Laser
{
protected:

	void effacer() override;
	void afficher() override;
	unsigned short Colour;

public:
	LaserVaisseau(unsigned short Colour, Coord c, TypeLaser typeLaser);
	~LaserVaisseau();
};