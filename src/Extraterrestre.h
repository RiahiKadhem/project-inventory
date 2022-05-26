#pragma once
#include "ObjetDeJeu.h"
/*
	Classe qui représente la base de l'évolution des d'extraterrestres qui tenterons 
	d'envahir la terre.
*/
class Extraterrestre : public ObjetDeJeu {
protected:
	char apparence; // Sert à contenir l'apparence de l'extraterrestre
	unsigned short valeurPoints; // Sert à contenir la valeur en points que l'extraterrestre donne lorsqu'il est détruit

	//Méthode qui sert à effacer l'extraterrestre à l'écran. Peut être redéfini au besoin dans une classe dérivée.
	void effacer() override;
	//Méthode qui sert à afficher l'extraterrestre à l'écran. Peut être redéfini au besoin dans une classe dérivée.
	void afficher() override;
public:
	//Constructeur qui sert à initialiser l'extraterrestre construit et l'affiche à l'écran
	Extraterrestre(Coord coord, char apparence, unsigned short valeurPoints);

	//Méthode qui retourne la valeur en point de l'extraterrestre
	unsigned short getValeurPoints() const;

};