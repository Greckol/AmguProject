#include <iostream>
#include <fstream>
#include <random>
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define A (-5)
#define B (5)
#define CORD_COUNT (50)

void create()
{
    std::fstream file("bin.bin", std::ios::binary | std::ios::out);
    if (!file.is_open()) return;
    bool choise;
    std::cout << "hand or random 1/0: ";
    std::cin >> choise;
    double cord_lts_x, cord_lts_y, leanght_side;
    double cord_x, cord_y;
    if (choise)
    {
        std::cout << "left top cord square (X/Y): ";
        std::cin >> cord_lts_x >> cord_lts_y;
        file.write(reinterpret_cast<const char*>(&cord_lts_x), sizeof(cord_lts_x));
        file.write(reinterpret_cast<const char*>(&cord_lts_y), sizeof(cord_lts_y));
        std::cout << "leanght_side: ";
        std::cin >> leanght_side;
        file.write(reinterpret_cast<const char*>(&leanght_side), sizeof(leanght_side));
        int count;
        std::cout << "Count pointers: ";
        std::cin >> count;
        for (; count > 0; --count)
        {
            std::cout << "cord_x: " << "cord_y:\n";
            std::cin >> cord_x >> cord_y;
            file.write(reinterpret_cast<const char*>(&cord_x), sizeof(cord_x));
            file.write(reinterpret_cast<const char*>(&cord_y), sizeof(cord_y));
        }
    }
    else
    {
        srand(time(0));
        cord_lts_x = A + rand() % (B - A + 1);
        cord_lts_y = A + rand() % (B - A + 1);
        file.write(reinterpret_cast<const char*>(&cord_lts_x), sizeof(cord_lts_x));
        file.write(reinterpret_cast<const char*>(&cord_lts_y), sizeof(cord_lts_y));

        leanght_side = 1 + rand() % (B - 1 + 1);
        file.write(reinterpret_cast<const char*>(&leanght_side), sizeof(leanght_side));

        for (int i = 0; i < CORD_COUNT; i++)
        {
            cord_x = A + rand() % (B - A + 1);
            cord_y = A + rand() % (B - A + 1);
            file.write(reinterpret_cast<const char*>(&cord_x), sizeof(cord_x));
            file.write(reinterpret_cast<const char*>(&cord_y), sizeof(cord_y));
        }
    }
    file.close();
}


int main()
{
    create();
    std::ifstream file("bin.bin", std::ios::binary);
    if (!file.is_open()) return 0;
    double cord_lts_x, cord_lts_y, leanght_side;
    file.read(reinterpret_cast<char*>(&cord_lts_x), sizeof(cord_lts_x));
    file.read(reinterpret_cast<char*>(&cord_lts_y), sizeof(cord_lts_y));
    file.read(reinterpret_cast<char*>(&leanght_side), sizeof(leanght_side));
    double cord_x, cord_y;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
    std::cout << "x:" << cord_lts_x << " y:" << cord_lts_y << " len:" << leanght_side << '\n';
    while (file.read(reinterpret_cast<char*>(&cord_x), sizeof(cord_x)) &&
        file.read(reinterpret_cast<char*>(&cord_y), sizeof(cord_y)))
    {
        if (cord_x > cord_lts_x && cord_x < cord_lts_x + leanght_side &&
            cord_y <= cord_lts_y && cord_y >= cord_lts_y - leanght_side)\
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "Accept" << " x " << cord_x << " " << "y " << cord_y << '\n';
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            std::cout << "Decline" << " x " << cord_x << " " << "y " << cord_y << '\n';
        }
    }
    file.close();
}

