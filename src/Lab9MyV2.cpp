#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
int main()
{
	setlocale(LC_ALL, "");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::ifstream file("Text.txt");
	if (!file.is_open()) return 0;
	std::string str;
	int counter = 1;
	while (std::getline(file, str, '.'))
	{
		std::cout << str;
	};
	_getch();
	system("cls");
	file.close();
	file.open("Text.txt");
	while (std::getline(file, str, '.'))
	{
		if (counter == 3)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		}
		std::cout << str;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		++counter;
	};
}
