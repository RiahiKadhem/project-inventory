#include "Vaisseau.h"
#include "UIKit.h"
#include <iostream>

Vaisseau::Vaisseau(char apparenceVaisseau, Coord c, Coord limiteGauche, Coord limiteDroite) : apparence(apparenceVaisseau), ObjetDeJeu(c, TypeObjetDeJeu::VAISSEAU), limiteGauche(limiteGauche), limiteDroite(limiteDroite) {
	this->afficher();
}

void Vaisseau::effacer() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << " ";
}

void Vaisseau::deplacer(Direction direction) {
	this->effacer();
	switch (direction)
	{
	case Direction::GAUCHE:
		if (this->coord.getX() > this->limiteGauche.getX()) {
			this->coord.setX(this->coord.getX() - 1);
		}
		break;
	case Direction::DROITE:
		if (this->coord.getX() < this->limiteDroite.getX()) {
			this->coord.setX(this->coord.getX() + 1);
		}
		break;
	}
	this->afficher();
}



void Vaisseau::afficher() {
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	std::cout << this->apparence;
}