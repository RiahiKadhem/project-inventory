#include <iostream>
#include "Partie.h"
#include "Menu.h"
using namespace std;

int main() {
	//D�mare une seule partie, la joue et la supprime imm�diatement lorsqu'elle est termin�e
	Partie* partie = new Partie();
	Menu* menu = new Menu();
	menu->startMenu(*partie);
	// partie->debuter();  
	delete partie;
	return 0;
}