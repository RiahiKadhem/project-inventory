#include "Endgame.h"
#include "Partie.h"
#include <iostream>
#include <Windows.h>
#include "UIKit.h"
#include <string>

void Endgame::lose(int valeur, Partie &partie)
{
	system("cls");
	std::string monTabStringLose[6];
	UIKit::color(5);
	monTabStringLose[0] = "        _____                          ____				        ";
	monTabStringLose[1] = "       / ____|                        / __ \\				        ";
	monTabStringLose[2] = "       | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __       ";
	monTabStringLose[3] = "       | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|  ";
	monTabStringLose[4] = "       | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |        ";
	monTabStringLose[5] = "        \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|    ";
	for (int i = 0; i < 6; i++)
	{
		Sleep(100);
		std::cout << monTabStringLose[i] << std::endl;
	}
	cout << "			Le socore est : " << ((valeur == 0) ? 0 : valeur / 2) << endl;
	cout << " Press any KEY to play again" << endl;
	int tryAgain;
	cin >> tryAgain;
	partie.debuter();
}

void Endgame::win(int valeur, Partie &partie)
{
	system("cls");
	std::string monTabStringWin[6];
	UIKit::color(5);
	monTabStringWin[0] = "     __   __           __        ___				";
	monTabStringWin[1] = "     \\ \\ / /__  _   _ \\ \\       /  /(_)  _   __";
	monTabStringWin[2] = "      \\ V / _ \\| | | | \\ \\ / \\ /  / | | |_\\ | |	";
	monTabStringWin[3] = "       | | (_) | |_| |  \\ V   V  /  | | | | \\ |	";
	monTabStringWin[4] = "       |_|\\___ /\\__,_|   \\_ / \\_/   |_| |_| |_| ";
	monTabStringWin[5] = "												";
	for (int i = 0; i < 6; i++)
	{
		Sleep(100);
		std::cout << monTabStringWin[i] << std::endl;
	}
	cout << "				Le socore est : " << valeur * 2 << endl;
	cout << " Press any KEY to play again" << endl;
	int tryAgain;
	cin >> tryAgain;
	partie.debuter();

}