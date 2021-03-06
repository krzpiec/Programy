// Zad7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//7. Proszę napisać funkcję, która przyjmuje dwa posortowane wektory liczb całkowitych i zwraca posortowany
//wektor zawierający wszystkie liczby.Nie można użyć tutaj funkcji sortującej.
#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <cstdlib>
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
void sortuj(std::vector<double>& myvec, const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int a = 0; a < n - 1; a++)
		{
			if (myvec[a] > myvec[a + 1])
			{
				std::swap(myvec[a], myvec[a + 1]);
			}
		}
	}
}
void wypisz(std::vector<double>& myvec, const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << std::setprecision(2) << std::setw(n) << std::fixed << myvec[i];
		std::cout << " ";
	}
}
void sumuj(std::vector<double>& myvec, std::vector<double>& myvec1, std::vector<double>&suma, const int n)
{	
	for (int i = 0; i < n; i++)
	{	
		//suma.insert(suma.begin(), myvec.begin(), myvec.end());
		suma[i] = myvec[i];
	}
	for (int i = n; i < 2 * n; i++)
	{
		suma[i] = myvec1[i-n];
	}
}

void wypisz1(std::vector<double>& myvec, const int n)
{
	for (int i = 0; i < 2*n; i++)
	{
		std::cout <<std::setprecision(2)<< std::setw(n) << std::fixed << myvec[i];
		std::cout << " ";
	}
}
int main()
{
	const int n = 5;
	std::vector<double> myvec(n);
	std::vector<double> myvec1(n);
	std::vector<double> suma(2*n);

	wyp(myvec, n);
	sortuj(myvec, n);
	wypisz(myvec, n);
	std::cout << " | ";
	wyp(myvec1, n);
	sortuj(myvec1, n);
	wypisz(myvec1, n);
	std::cout << std::endl;
	sumuj(myvec, myvec1, suma, n);
	wypisz1(suma, n);
	return 0;
}

