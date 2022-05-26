#include "VaisseauBoss.h"
#include "UIKit.h"


VaisseauBoss::VaisseauBoss(char apparenceGauche, char apparenceVaisseau, char apparenceDroite, Coord c, Coord limiteGauche, Coord limiteDroite) : Vaisseau (apparenceVaisseau, c, limiteGauche, limiteDroite)
{
	this->apparenceGauche = apparenceGauche;
	this->apparenceDroite = apparenceDroite;
	this->afficher();
}


VaisseauBoss::~VaisseauBoss()
{
}

void VaisseauBoss::afficher()
{
	UIKit::gotoXY(this->coord.getX() -1, this->coord.getY());
	cout << apparenceGauche;
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	cout << apparence;
	UIKit::gotoXY(this->coord.getX() +1, this->coord.getY());
	cout << apparenceDroite;
}

void VaisseauBoss::effacer()
{
	UIKit::gotoXY(this->coord.getX() - 1, this->coord.getY());
	cout << " ";
	UIKit::gotoXY(this->coord.getX(), this->coord.getY());
	cout << " ";
	UIKit::gotoXY(this->coord.getX() + 1, this->coord.getY());
	cout << " ";
}
