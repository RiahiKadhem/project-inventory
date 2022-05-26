#include "Laser.h"
#include "UIKit.h"
#include <iostream>

Laser::Laser(Coord c, TypeLaser typeLaser) : ObjetDeJeu(c, TypeObjetDeJeu::LASER) {
	this->typeLaser = typeLaser;
	switch (this->typeLaser) {
	case TypeLaser::JOUEUR:
		this->coord.setY(this->coord.getY() - 1);
		break;
	case TypeLaser::EXTRATERRESTRE:
		//UIKit::color(12);
		this->coord.setY(this->coord.getY() + 1);
		break;
	}
}

void Laser::effacer() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << " ";
}

void Laser::deplacer() {
	this->effacer();
	switch (this->typeLaser)
	{
	case TypeLaser::JOUEUR:
	    this->coord.setY(this->coord.getY() - 1);
		break;
	case TypeLaser::EXTRATERRESTRE:
		this->coord.setY(this->coord.getY() + 1);
		break;
	}

	if ((this->coord.getY() <= 2 && this->typeLaser == TypeLaser::JOUEUR) || (this->coord.getY() >= 22 && this->typeLaser == TypeLaser::EXTRATERRESTRE)) {
		this->detruire();
	}

	if (this->isActif()) {
		this->afficher();
	}
}

TypeLaser Laser::getTypeLaser() const
{
	return this->typeLaser;
}

void Laser::afficher() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << (char)this->typeLaser;
}

void Laser::detruire() {
	this->effacer();
	ObjetDeJeu::detruire();
}