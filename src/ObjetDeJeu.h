#pragma once
#include "Coord.h"
#include "TypeObjetDeJeu.h"

/*
	Classe de base servent à contenir les données membre et méthodes commune à
	toutes les type d'objets de jeux disponible dans le programme.
*/
class ObjetDeJeu {
protected:
	Coord coord; // l'emplacement sur l'axe des x et y de l'objet de jeu
	bool actif; // si l'objet est actif ou non
	TypeObjetDeJeu type; // le type de l'objet de jeu
	
	/*
		Méthode appelée pour effacer un objet à l'écran. Méthode virtuelle 
		pure qui doit être redéfinie dans une classe dérivée.
	*/
	virtual void effacer() = 0;
	/*
		Méthode appelée pour afficher un objet à l'écran. Méthode virtuelle
		pure qui doit être redéfinie dans une classe dérivée.
	*/
	virtual void afficher() = 0;
public:
	ObjetDeJeu(Coord coord, TypeObjetDeJeu type);
	virtual ~ObjetDeJeu(); 
	/*
		Méthode qui retourne true si les coordonnées x et y de l'instance en 
		cours sont égales au coordonnées x et y de l'OBJET_DE_JEU, sinon elle 
		retourne false.

		Peut être redéfinie au besoin dans une classe dérivée.
	*/
	virtual bool detecterCollision(const ObjetDeJeu& OBJET_DE_JEU) const;
	//Retourne les coordonnées de l'instance
	const Coord& getCoord() const;
	//Retourne l'état actif ou non de l'instance
	bool isActif() const;
	//Méthode servant à détruire l'objet en cours. Peut être redéfinie dans un classe dérivée au besoin
	virtual void detruire();
	//Retourne le type de l'objet de jeu
	TypeObjetDeJeu getType() const;
};

