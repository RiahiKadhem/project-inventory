#pragma once
/*
	Classe qui sert à contenir les coordonnées x et y des différents type d'objet 
	de jeu du programme.
*/
class Coord {

	int x;
	int y;
public:
	Coord(int x, int y);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

