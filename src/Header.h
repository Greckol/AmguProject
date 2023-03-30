#pragma once


class Pointer
{
public:
	Pointer(); 
	Pointer(int x, int y);
	Pointer(const Pointer& point);
	~Pointer();
	
	int GetX() const;
	int GetY() const;

	void Print() const;
	
	double Lenght() const;
	
	bool prendlezhnost(int a, int b, int c) const;
		
protected:
	int cord_X;
	int cord_Y;
};

class PointerFull: public Pointer
{
public:
	PointerFull();
	PointerFull(int x, int y);
	bool PointerEuqul(const Pointer& a, const Pointer& b) const;
	PointerFull PointerSum(const Pointer& p1, const Pointer& p2);
	PointerFull PointerMulti(Pointer& point, const int& number);
	PointerFull operator+(const Pointer& p);
	PointerFull& operator*=(const Pointer& p);
	bool operator==(const Pointer& p);
	bool operator!=(const Pointer& p);

};

