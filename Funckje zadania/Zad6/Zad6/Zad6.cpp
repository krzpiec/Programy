// Zad6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <cstdlib>
//6. Proszę napiszą funkcję, która przyjmuje wektor liczb zmiennoprzecinkowych i zwraca wektor tychże
//liczb w odwrotnej kolejności

void wyp(std::vector<double>& myvec, const int n)
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double> rozklad(0, 5);
	for (int i = 0; i < n; i++)
	{
		myvec[i] = rozklad(silnik);
	}
}

void wypisz(std::vector<double>& myvec, const int n)
{	
	for (int i = 0; i < n; i++)
	{
		std::cout << std::setw(n) << std::fixed << myvec[i] << std::endl;;
	}
}

void odwr(std::vector<double>& myvec, const int n)
{	
	
	for (int i = 0; i < n/2; i++)
	{	
		std::swap(myvec[i], myvec[myvec.size() -1 -i]);
	}
}

int main()
{	
	const int n = 5;
	std::vector<double> myvec(n);
	wyp(myvec, n);
	wypisz(myvec, n);
	std::cout << std::endl;
    odwr(myvec, n);
	wypisz(myvec, n);

	return 0;
}