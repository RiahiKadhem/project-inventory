#include "Menu.h"
#include "Partie.h"
#include <string>
#include <iostream>
#include<Windows.h>
#include "UIKit.h"
#include "Instruction.h"




void Menu::startMenu(Partie &partie)

{
	Instruction instruction;
	std::string monTabString[22];
	monTabString[0] = " ";
	monTabString[1] = " ";
	monTabString[2] = " ";
	monTabString[3] = "                                                _,-ddd888888bbb-._           ";
	monTabString[4] = "                                              d88888888888888888888b         ";
	monTabString[5] = "                                            d888888888888888888888888b       ";
	monTabString[6] = "                                           6888888888888888888888888889      ";
	monTabString[7] = "                                           68888b8""8q8888888p8""8d88889     ";
	monTabString[8] = "                                           `d8887     p88888q     4888b'     ";
	monTabString[9] = "                                            `d8887    p88888q    4888b'      ";
	monTabString[10] = "                                              `d887   p88888q   488b'        ";
	monTabString[11] = "                                                `d8bod8888888dob8b'          ";
	monTabString[12] = "                                                  `d88888888888d'Arif        ";
	monTabString[13] = "                                                    `d8888888b' Amine        ";
	monTabString[14] = "                                                     `d8888b'  Kadhem        ";
	monTabString[15] = "                                                       `bd'                  ";
	monTabString[16] = "                    _____                          ____                    __               ";
	monTabString[17] = "                   / ___/____  ____ _________     /  _/___ _   ______ ____/ /__  __________ ";
	monTabString[18] = "                   \\__ \\/ __ \\/ __ `/ ___/ _ \\   / // __ \\ | / / __ `/ __  / _ \\/ ___/ ___/ ";
	monTabString[19] = "                 __ _/ / /_/ / /_/ / /__/  __/ _/ // / / / |/ / /_/ / /_/ /  __/ /  (__  )  ";
	monTabString[20] = "                /____ / .___/\\__,_/\\___/\\___/ /___/_/ /_/|___/\\__,_/\\__,_/\\___/_/  /____/   ";
	monTabString[21] = "                     /_/                                                                     ";
	UIKit::color(3);
	for (int i = 0; i < 22; i++)
	{
		Sleep(100);
		if (i==16)
		{
			UIKit::color(6);
		}
		std::cout << monTabString[i] << std::endl;
	}

UIKit::color(10);
	std::cout << "                                    " << std::endl;
	std::cout << "     :[1]BEGIN:" << std::endl;        
	std::cout << "                                    " << std::endl;
	//std::cout << "     :[2]HIGH SCORES:" << std::endl;
	//std::cout << "                                    " << std::endl;
	std::cout << "     :[2]INSTRUCTIONS:" << std::endl;
	std::cout << "                                    " << std::endl;
	std::cout << "     :[3]Exit:" << std::endl;

	const short MIN = 1;
	const short MAX = 4;
	
	switch (validerPlage(MIN, MAX))
	{
	case 1:
		partie.debuter();
		break;
	case 2:
		instruction.afficherInstruction();
		break;
	case 3:

		break;
	}
	system("cls");
        
}


short Menu::validerNumerique() 
{
	short valeur;
	std::cin >> valeur;
	while (std::cin.fail() || std::cin.peek() != '\n') {
		std::cin.clear();
		std::cin.ignore(512, '\n');
		std::cout << "Valeur numerique seulement : ";
		std::cin >> valeur;
	}
	std::cin.ignore(512, '\n');
	return valeur;
}

short Menu::validerPlage(const short MIN, const short MAX) 
{
	short valeur = validerNumerique();
	while (valeur < MIN || valeur > MAX) {
		std::cout << "Valeur entre " << MIN << " et " << MAX << " seulement : ";
		valeur = validerNumerique();
	}

	return valeur;
}



