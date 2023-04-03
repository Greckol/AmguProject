#include <iostream>
#include "Animals.h"

void sort(Fish* ptr, int size);

int main()
{
	Mleco human("human", "premohod ", "zemlia", Mleco::TYPE::VSEAD);
	Bird sinicha("sinicha", "ptichi", "vozdyx", Bird::TYPE::DIKAY_NE_PERELET);
	Fish karas("karas", "ribi", "voda", Fish::TYPE::MORSKAY);

	human.Show();
	sinicha.Show();
	karas.Show();

	//////////////////////////////////////////////////////////////
	Fish arr[3];
	*arr = Fish("karas", "korotkoe", "Zeia", Fish::TYPE::MORSKAY);
	*(arr + 1) = Fish("okyn", "dlinnoe", "Lmansh", Fish::TYPE::MORSKAY);
	*(arr + 2) = Fish("shyka", "dlinnoe", "Amur", Fish::TYPE::PRESNOVODNAY);
	
	sort(arr, 3);
	for (int i = 0; i < 3; i++)
	{
		(arr + i)->Show();
	}
}

void sort(Fish* ptr, int size)
{
	for (int i = 1; i < size; i++)
	{
		if ((ptr + i - 1)->get_type() == Fish::TYPE::MORSKAY)
		{
			auto temp = *(ptr + i - 1);
			for (int b = size - 1; b > 0; b--)
			{
				if ((ptr + b)->get_type() == Fish::TYPE::PRESNOVODNAY)
				{
					*(ptr + i - 1) = *(ptr + b);
					*(ptr + b) = temp;
				}
			}
		}
		
	}
}

