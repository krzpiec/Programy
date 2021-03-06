// Zad3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//3. Proszę napisać funkcję, która przyjmuje tablicę liczb zmiennoprzecinkowe i rozmiar tablicy, i odwraca
//kolejność elementów w tablicy.//Moja modyf: Wypelnij liczbami pseudolos, posegreguj, wypisz posegregowane, odwroc elementy
#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <cstdlib>
void wypelnij(double tab[], const int n)
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double> rozklad(0, 5);
	for (int i = 0; i < n; i++)
	{
		tab[i] = rozklad(silnik);
	}
}
void szereg(double tab[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int a = 0; a < n-1; a++)
		{
			if (tab[a] > tab[a + 1])
			{
				std::swap(tab[a], tab[a + 1]);
			}
		}
	}
}
void wypisz(double tab[], const int n)
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
	double tab[n] = { 0 };
	wypelnij(tab, n);
	wypisz(tab, n);
	szereg(tab, n);
	std::cout<<std::endl;
	wypisz(tab, n);
}

