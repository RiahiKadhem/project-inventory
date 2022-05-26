#pragma once
#include "ObjetDeJeu.h"
#include "TypeLaser.h"
/*
	Classe servant à représenter tout type de laser pouvant être utilisé dans le jeu (Joueur ou Extraterrestre).
*/
class Laser : public ObjetDeJeu {
protected:
	TypeLaser typeLaser; // Représente le type de laser

	
	void effacer() override;
	void afficher() override;
public:

	Laser(Coord c, TypeLaser typeLaser);
	/*
		Méthode qui sert à déplacer en mémoire et à l'écran un laser selon son type.
	*/
	virtual void deplacer();
	/*
		Retourne le type de laser.
	*/
	TypeLaser getTypeLaser() const;
	/*
		Redfinition de la méthode détruire de ObjetDeJeu.
	*/
	void detruire() override;
};