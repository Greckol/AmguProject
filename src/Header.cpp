#include "Header.h"
#include <cmath>
#include <iostream>

Pointer::Pointer() : cord_X(0), cord_Y(0)
{
}

Pointer::Pointer(int x, int y) : cord_X(x), cord_Y(y)
{
}

Pointer::Pointer(const Pointer& point) : cord_X(point.cord_X), cord_Y(point.cord_Y)
{
}

Pointer::~Pointer()
{
}

int Pointer::GetX() const
{
	return cord_X;
}

int Pointer::GetY() const
{
	return cord_Y;
}

void Pointer::Print() const
{
	std::cout << "coords (" << cord_X << ';' << cord_Y << ")\n";
}

double Pointer::Lenght() const
{
	return sqrt((cord_X * cord_X + cord_Y * cord_Y));
}

bool Pointer::prendlezhnost(int a, int b, int c) const
{
	if (a * cord_X + b * cord_Y + c == 0) return 1;
	return 0;
}

PointerFull::PointerFull(): Pointer()
{
}

PointerFull::PointerFull(int x, int y): Pointer(x, y)
{
}

bool PointerFull::PointerEuqul(const Pointer& a, const Pointer& b) const
{
	return (a.GetX() == b.GetX() && a.GetY() == b.GetY());
}

PointerFull PointerFull::PointerSum(const Pointer& p1, const Pointer& p2)
{
	return PointerFull(p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY());
}

PointerFull PointerFull::PointerMulti(Pointer& point, const int& number)
{
	return PointerFull(point.GetX() * number, point.GetY() * number);
}

PointerFull PointerFull::operator+(const Pointer& p)
{
	return PointerFull(cord_X + p.GetX(), cord_Y + p.GetY());
}

PointerFull& PointerFull::operator*=(const Pointer& p)
{
	cord_X *= p.GetX();
	cord_Y *= p.GetY();
	return *this;
}

bool PointerFull::operator==(const Pointer& p)
{
	if (p.GetX() == cord_X && p.GetY() == cord_Y) return 1;
	return 0;
}

bool PointerFull::operator!=(const Pointer& p)
{
	if (p.GetX() == cord_X && p.GetY() == cord_Y) return 0;
	return 1;
}
