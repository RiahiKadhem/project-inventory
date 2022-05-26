#include "Partie.h"
#include "Vaisseau.h"
#include "Extraterrestre.h"
#include "Laser.h"
#include "Martien.h"
#include "UIKit.h"
#include <iostream>
#include <conio.h>
#include<Windows.h>
#include"Endgame.h"
#include"VaisseauBoss.h"
#include "time.h"

void Partie::debuter()
{
	srand(time(0));
	system("cls");
	UIKit::curseurVisible(false);
	UIKit::setDimensionFenetre(0, 0, 70, 30);
	UIKit::cadre(7, 2, 52, 25, 15);
	bool partieTermine = false;

	//Faire apparaitre le vaisseau
	Coord coordonneesDepartVaisseau(30, 21);
	Coord limiteMouvementGauche(8, 20);
	Coord limiteMouvementDroite(50, 20);
	char apparenceDuVaisseau = 'A';
	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite);

	//test timer dinamic
	int cmp = 0; // valeur qui va centenir le compteur apres la fin d'un niveau
	double myTimer = 100; // timer du sleep en ms
	int sortieDeBoucle = 0; //la valeur qui va permetre de sortir de la boucle et finir le jeu

	//creer une variable score
	int score = 0; //le score du joueur
	int timer = 0; //Timer p/s
	int cpt = 0;
	//cpt % (rand() % 20 + 1) == 5
	/*Creer un tableau de martiens avec leur coord*/
	const int nbrMartiens = 15;
	Martien *myTabMartien[nbrMartiens];
	int tempX = 10;
	int tempY = 10;
	for (int i = 0; i < nbrMartiens-2; i++)
	{
		Coord maCoord(tempX, tempY);
		myTabMartien[i] = new Martien(Coord(rand() % 38 + 9, rand() % 12 + 3), 'W', 100);
		
	}
	myTabMartien[13] = new Martien(Coord(rand() % 38 + 9, rand() % 12 + 3), 'O', 200);
	myTabMartien[14] = new Martien(Coord(rand() % 38 + 9, rand() % 12 + 3), 'O', 200);
	/*creer un tableau dynamic de lazer*/
	const int tabLaserSize = 40;
	int cmpLaser = 0;
	Laser *myTabLaser[tabLaserSize];

	const int tabLaserMartienSize = 50;
	int cmpLaserMartiens = 0;
	Laser *myTabLaserMartien[tabLaserMartienSize];

	/*inicialiser le tableau de laser et initialiser la valeur actif a false*/
	for (int i = 0; i < tabLaserSize; i++)
	{
		myTabLaser[i] = new Laser(vaisseau.getCoord(), TypeLaser::JOUEUR);
		myTabLaser[i]->detruire();
	}

	for (int i = 0; i < tabLaserMartienSize; i++)
	{
		myTabLaserMartien[i] = new Laser(vaisseau.getCoord(), TypeLaser::EXTRATERRESTRE);
		myTabLaserMartien[i]->detruire();
	}
	int nbVie = 3; //nombre de vie du joueur
	Endgame endgame;

	do {

		//Récupérer la touche appuyée par l'utilisateur
		if (GetAsyncKeyState(VK_SPACE))
		{
			delete myTabLaser[cmpLaser];
			myTabLaser[cmpLaser] = new Laser(vaisseau.getCoord(), TypeLaser::JOUEUR);
			cmpLaser++;
		}

		for (int i = 0; i < tabLaserSize; i++)
		{
			if (myTabLaser[i]->getCoord().getY() == 3)
			{
				UIKit::gotoXY(myTabLaser[i]->getCoord().getX(), myTabLaser[i]->getCoord().getY());
				std::cout << " ";
			}
			if (myTabLaser[i]->isActif() == true && myTabLaser[i]->getCoord().getY() > 3)
			{
				UIKit::color(6);
				myTabLaser[i]->deplacer();
				UIKit::color(5);
			}
		}
		if (cmpLaser == tabLaserSize - 1)
		{
			cmpLaser = 0;
		}

		//Effectuer action en fonction de la touche appuyé par l'utilisateur
		//Ici on peut soit déplacer le vaiseau à gauche ou à droite, soit tirer un laser
		if (GetAsyncKeyState(VK_LEFT)) {
			vaisseau.deplacer(Direction::GAUCHE);
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			vaisseau.deplacer(Direction::DROITE);
		}

		//Déplacer les lasers du vaisseau et des extraterrestres		

		//Déplacer les extraterrestres		

		for (int i = 0; i < nbrMartiens; i++)
		{

			if (myTabMartien[i]->isActif() == true)
			{
				UIKit::color(4);
				myTabMartien[i]->deplacer();
			}
		}

		//Faire tirer les extraterrestres

		int valeurRandom = rand() % nbrMartiens;				//choisir un numéro aléatoire entre 0 et 10(martiens)
		int posMartienHasard = -1;
		if (myTabMartien[valeurRandom]->isActif()) {	//le martien doit être actif pour tirer sinn on recommence 
			posMartienHasard = valeurRandom;

			Coord coordMartienHazard(myTabMartien[posMartienHasard]->getCoord().getX(), myTabMartien[posMartienHasard]->getCoord().getY());
			delete myTabLaserMartien[cmpLaserMartiens];
			myTabLaserMartien[cmpLaserMartiens] = new Laser(coordMartienHazard, TypeLaser::EXTRATERRESTRE);
			cmpLaserMartiens++;

		}

		for (int i = 0; i < tabLaserMartienSize - 1; i++)
		{
			if (myTabLaserMartien[i]->isActif() == true && myTabLaserMartien[i]->getCoord().getY() < 22)
			{
				UIKit::color(2);
				myTabLaserMartien[i]->deplacer();
			}
		}

		if (cmpLaserMartiens == tabLaserMartienSize - 1)
		{
			cmpLaserMartiens = 0;
		}


		//Vérifier collision entre laser et joueur ou ennemis
		for (int i = 0; i < tabLaserSize; i++)
		{
			for (int j = 0; j < nbrMartiens; j++)
			{
				if (myTabLaser[i]->getCoord().getY() == myTabMartien[j]->getCoord().getY() && myTabLaser[i]->getCoord().getX() == myTabMartien[j]->getCoord().getX() && myTabLaser[i]->isActif() == true && myTabMartien[j]->isActif() == true)
				{
					score += myTabMartien[j]->getValeurPoints();
					myTabLaser[i]->detruire();
					myTabMartien[j]->detruire();
				}
			}
		}

		//Faire apparaitre nouveau extraterrestre

		//Mettre à jour le score affiché	

		UIKit::gotoXY(9, 2);
		UIKit::color(9);
		std::cout << " Score : " << score << std::endl;



		//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0)		

		//Vérifier si on perd si le nombre d'extra terrestre est à 15+ ou 
		//qu'un laser extraterrestre nous a atteint

		for (int i = 0; i < tabLaserMartienSize; i++)
		{

			if (myTabLaserMartien[i]->getCoord().getY() == vaisseau.getCoord().getY() && myTabLaserMartien[i]->getCoord().getX() == vaisseau.getCoord().getX() && myTabLaserMartien[i]->isActif() == true)
			{
				nbVie--;
			}
		}
		if (nbVie == 0)
		{
			endgame.lose(score,*this);
		}
		// Timer
		if (cpt % 10 == 0)
		{
			timer++;

		}
		UIKit::color(5);
		UIKit::gotoXY(15, 1);
		cout << "                   " << " Temp de jeu : " << timer << " " << endl;
		//UIKit::color(5);



//test difficulté
		int testSiActif = 0;
		for (int i = 0; i < nbrMartiens; i++)
		{
			if (myTabMartien[i]->isActif() == true)
			{
				testSiActif++;
			}
		}
		//UIKit::color(15);
		UIKit::gotoXY(10, 23);
		cout << "           " << " Nombre de vie " << nbVie << " " << endl;
		//UIKit::color(90);

		if (testSiActif == 0)
		{
			sortieDeBoucle++;
			int valTempCoordX = 12;
			int valTempCoordY = 10;
			myTimer -= 20;
			for (int i = 0; i < nbrMartiens-2; i++)
			{
				Coord maCoord(valTempCoordX, valTempCoordY);
				delete myTabMartien[i];
				myTabMartien[i] = new Martien(Coord(rand() % 35 + 11, rand() % 12 + 3), 'W', 200);
				valTempCoordX = valTempCoordX + 4;
			}
			myTabMartien[13] = new Martien(Coord(rand() % 38 + 9, rand() % 12 + 3), 'O', 300);
			myTabMartien[14] = new Martien(Coord(rand() % 38 + 9, rand() % 12 + 3), 'O', 300);
		}

		if (sortieDeBoucle == 3)
		{
			endgame.win(score,*this);
		}
		UIKit::color(11);
		UIKit::gotoXY(vaisseau.getCoord().getX(), vaisseau.getCoord().getY());
		cout << "A";
		UIKit::color(10);

		cpt++;
		Sleep(myTimer);
	} while (partieTermine == false);
	system("cls");
}
