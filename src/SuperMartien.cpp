#include "SuperMartien.h"
#include <random>

SuperMartien::SuperMartien(Coord coord, char apparence, unsigned short valeurPoints) : Extraterrestre(coord, apparence, valeurPoints)/*, toggle(rand() % 2)*/ {}

void SuperMartien::deplacer() {
	this->effacer();

	
	//this->coord.setX(this->coord.getX() + (toggle ? 1 : -1));
	//toggle = !toggle;

	this->afficher();
}