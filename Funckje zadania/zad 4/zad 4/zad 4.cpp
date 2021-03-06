// zad 4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <iomanip>


void wyp(int tab[], const int n)
{
		srand(time(0));
		for (int i = 0; i < n; i++)
		{
			tab[i] = std::rand()%50;
		}
}

int parz(int tab[], const int n)
{
	int parzyste = 0;
	for (int i = 0; i < n; i++)
	{
		if (tab[i] % 2 == 0)
		{
			parzyste++;
		}
	}
	return parzyste;
}

void wypisz(int tab[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << std::setw(n) << std::fixed << tab[i];
		std::cout << "  ";
	}
}

int main()
{
	const int n = 5;
	int tab[n] = { 0 };
	wyp(tab, n);
	wypisz(tab, n);
	std::cout << std::endl;
	std::cout<<parz(tab, n);
}
