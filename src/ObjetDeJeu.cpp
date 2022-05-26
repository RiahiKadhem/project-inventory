#include "ObjetDeJeu.h"
ObjetDeJeu::ObjetDeJeu(Coord coord, TypeObjetDeJeu type) : coord(coord), type(type), actif(true) {}

ObjetDeJeu::~ObjetDeJeu()
{
}

bool ObjetDeJeu::detecterCollision(const ObjetDeJeu& OBJET_DE_JEU) const
{
	return this->coord.getX() == OBJET_DE_JEU.coord.getX() && this->coord.getY() == OBJET_DE_JEU.coord.getY();
}

const Coord& ObjetDeJeu::getCoord() const
{
	return this->coord;
}

bool ObjetDeJeu::isActif() const
{
	return this->actif;
}

void ObjetDeJeu::detruire()
{
	this->actif = false;
}

TypeObjetDeJeu ObjetDeJeu::getType() const
{
	return this->type;
}
