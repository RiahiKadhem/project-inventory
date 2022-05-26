#pragma once
#include "Direction.h"
#include "ObjetDeJeu.h"
#include "UIKit.h"
/*
	Cette classe représente le vaisseau de base qui sera piloté
	par le joueur.
*/
class Vaisseau : public ObjetDeJeu {
protected:
	char apparence; // Sert à contenir l'apparence du vaisseau de base
	Coord limiteGauche; // Sert à contenir la limite de déplacement de gauche du vaisseau 
	Coord limiteDroite; // Sert à contenir la limite de déplacement de droite du vaisseau
	
	void effacer() override;
	void afficher() override;
public:
	//Constructeur servant à initialiser un vaisseau et l'afficher à l'écran.
	Vaisseau(char apparenceVaisseau, Coord c, Coord limiteGauche, Coord limiteDroite);
	/*
		Méthode qui sert à déplacer en mémoire et sur l'écran le vaisseau.
		Celle-ci peut être redéfinie par une classe dérivée au besoin 
		s'il y a lieu.
	*/
	virtual void deplacer(Direction direction);
};