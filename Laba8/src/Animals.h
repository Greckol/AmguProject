#pragma once
#include <string>

class Animal
{
public:
	Animal();
	Animal(std::string, std::string, std::string);
	void virtual Show();
private:
	std::string title;
	std::string kind;
	std::string habitat;
};

class Mleco : public Animal
{
public:
	enum class TYPE
	{
		TRAVOADNOE, HISHNOE, VSEAD
	};

	Mleco();
	Mleco(std::string title, std::string kind, std::string habitat, TYPE type);
	void Show() override;
private:
	TYPE type;
};

class Fish : public Animal
{
public:
	enum class TYPE
	{
		MORSKAY, PRESNOVODNAY
	};

	Fish();
	Fish(std::string title, std::string kind, std::string habitat, TYPE type);
	void Show() override;
	TYPE get_type();
private:
	TYPE type;
};

class Bird : public Animal
{
public:
	enum class TYPE
	{
		DOMASHNIY, DIKAY_PERELET, DIKAY_NE_PERELET
	};

	Bird();
	Bird(std::string title, std::string kind, std::string habitat, TYPE type);
	void Show() override;
private:
	TYPE type;
};
