#pragma once
#include "Extraterrestre.h"
/*
	Cette classe représente l'évolution de l'extraterrestre qui à la 
	possibilité de se déplacer de gauche à droite pour tenter d'éviter 
	les tirs du joueur. 
*/
class Martien : public Extraterrestre {
protected:
	bool toggle; // Information servant à controler si l'extraterrestre se déplace à gauche ou à droite lors de l'appel de la méthode void deplacer();
public:
	Martien(Coord coord, char apparence, unsigned short valeurPoints);
	// Méthode qui sert à déplacer en mémoire et à l'écran un Martien
	virtual void deplacer();
};



