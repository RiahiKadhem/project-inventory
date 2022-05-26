#include "Extraterrestre.h"
#include "UIKit.h"
#include <iostream>
Extraterrestre::Extraterrestre(Coord coord, char apparence, unsigned short valeurPoints) : ObjetDeJeu(coord, TypeObjetDeJeu::EXTRATERRESTRE), apparence(apparence), valeurPoints(valeurPoints) {
	this->afficher();
}

void Extraterrestre::effacer() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << " ";
}

void Extraterrestre::afficher() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << this->apparence;
}

unsigned short Extraterrestre::getValeurPoints() const
{
	return this->valeurPoints;
}
