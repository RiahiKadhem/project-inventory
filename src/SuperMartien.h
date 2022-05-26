#pragma once
#include "Extraterrestre.h"
class SuperMartien :
	public Extraterrestre
{
protected:
//	bool toggle;
public:
	SuperMartien(Coord coord, char apparence, unsigned short valeurPoints);
	// Méthode qui sert à déplacer en mémoire et à l'écran un Martien
	void deplacer();
};

