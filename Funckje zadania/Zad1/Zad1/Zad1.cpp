// Zad1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


//1. Proszę napisać funkcję, która przyjmuje pięć liczb zmiennoprzecinkowych i zwraca ich minimum.
#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
void wypelnij(double tab[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::default_random_engine silnik;
		silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
		std::normal_distribution<double> rozklad(0, 2);
		tab[i] = rozklad(silnik);
	}
}
	double znajdz(double tab[], const int n)
	{
		double najmniejsza=tab[0];
		for (int i = 1; i < n; i++)
		{
			if (tab[i] < najmniejsza)
			{
				najmniejsza = tab[i];
			}
		}
		return najmniejsza;
	}


int main()
{	
	const int n = 5;
	double tab[n] = { 0 };
	wypelnij(tab, n);
	std::cout << znajdz(tab, n) << std::endl;
 
}
