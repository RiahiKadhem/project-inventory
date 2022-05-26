#pragma once
#include "Partie.h"

class Menu
{
public:

	void startMenu(Partie &partie);
	short validerNumerique();
	short validerPlage(const short MIN, const short MAX);
};

