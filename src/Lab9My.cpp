#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>


int main()
{
	setlocale(LC_ALL, "");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::ifstream stream("Text.txt");
	if (stream.is_open())
	{
		int sentenceCount = 0;
		std::string str, Full;
		while (std::getline(stream, str))
		{
			std::cout << str << '\n';
			Full += str;
		}

		std::string* ptr = new std::string[30];
		for (const char& i : Full)
		{
			*(ptr + sentenceCount) += i;
			i == '.' ? ++sentenceCount : 1;
		}
		std::cout << "sentenceCount: " << sentenceCount << '\n';

		_getch();
		system("cls");
		for (int i = 0; i < sentenceCount; i++)
		{

			if (i != 2)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				std::cout << *(ptr + i) << '\n';
			}
			else
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << *(ptr + i) << '\n';
			}
				
				
		}

	}
	
}
