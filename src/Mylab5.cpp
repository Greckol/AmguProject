#include <iostream>
#include "Header.h"

int main()
{
	PointerFull b(2, 3);
	PointerFull c(5, 6);
	auto k = b + c;
	k.Print();
}