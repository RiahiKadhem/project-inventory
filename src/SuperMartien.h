#pragma once
#include "Extraterrestre.h"
class SuperMartien :
	public Extraterrestre
{
protected:
//	bool toggle;
public:
	SuperMartien(Coord coord, char apparence, unsigned short valeurPoints);
	// M�thode qui sert � d�placer en m�moire et � l'�cran un Martien
	void deplacer();
};

