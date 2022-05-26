#pragma once
#include "Vaisseau.h"
class VaisseauBoss :
	public Vaisseau
{
	char apparenceGauche;
	char apparenceDroite;

public:
	VaisseauBoss(char apparenceGauche, char apparenceVaisseau, char apparenceDroite, Coord c, Coord limiteGauche, Coord limiteDroite);
	~VaisseauBoss();

	void afficher() override;
	void effacer() override;
};

