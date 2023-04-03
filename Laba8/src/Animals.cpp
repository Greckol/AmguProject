#include "Animals.h"
#include <iostream>
Mleco::Mleco() : Animal()
{
	type = TYPE::TRAVOADNOE;
}

Mleco::Mleco(std::string title, std::string kind, std::string habitat, TYPE type): 
	Animal(title, kind, habitat), type(type)
{
}

void Mleco::Show()
{
	Animal::Show();
	if (type == TYPE::TRAVOADNOE) std::cout << "Travoadnoe\n";
	else if (type == TYPE::HISHNOE) std::cout << "Hishnoe\n";
	else { std::cout << "Vseadnoe\n"; }
}

Animal::Animal(): title(""), kind(""), habitat("")
{
}

Animal::Animal(std::string title, std::string kind, std::string habitat):
	title(title), kind(kind), habitat(habitat)
{
}

void Animal::Show()
{
	std::cout << "Title:" << title <<
		" Kind:" << kind << " Habitat:" << habitat << " ";
}

Fish::Fish() : Animal()
{
	type = TYPE::MORSKAY;
}

Fish::Fish(std::string title, std::string kind, std::string habitat, TYPE type):
	Animal(title, kind, habitat), type(type)
{
}

void Fish::Show()
{
	Animal::Show();
	if (type == TYPE::MORSKAY) std::cout << "Morskay\n";
	else { std::cout << "Presnovodnay\n"; }
}

Fish::TYPE Fish::get_type()
{
	return type;
}

Bird::Bird(): Animal()
{
	type = TYPE::DOMASHNIY;
}

Bird::Bird(std::string title, std::string kind, std::string habitat, TYPE type):
	Animal(title, kind, habitat), type(type)
{
}

void Bird::Show()
{
	Animal::Show();
	if (type == TYPE::DOMASHNIY) std::cout << "Domashniy\n";
	else if (type == TYPE::DIKAY_PERELET) std::cout << "Dikay_perelitnay\n";
	else { std::cout << "Dikay_ne_perelitnay\n"; }
}
