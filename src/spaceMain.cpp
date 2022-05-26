#include <iostream>
#include "Partie.h"
#include "Menu.h"
using namespace std;

int main() {
	//Démare une seule partie, la joue et la supprime immédiatement lorsqu'elle est terminée
	Partie* partie = new Partie();
	Menu* menu = new Menu();
	menu->startMenu(*partie);
	// partie->debuter();  
	delete partie;
	return 0;
}