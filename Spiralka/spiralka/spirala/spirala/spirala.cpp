// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <random>

int main()
{
	const int w = 8;
	const int k = 8;

	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double> rozklad(0, 5);

	double tablica[w][k] = { 0 };
	double sumaw[w] = { 0 };
	double sumak[k] = { 0 };

	for (int i = 0; i < w; i++)
	{
		for (int a = 0; a < k; a++)
		{
			tablica[i][a] = rozklad(silnik);
			sumaw[i] += tablica[i][a];
		}
	}

	for (int i = 0; i < k; i++)
	{
		for (int a = 0; a < w; a++)
		{
			sumak[i] += tablica[a][i];
		}
	}
	

	for (int x = 0; x < w; x++)

	{
		for (int y = 0; y < k; y++)
		{
			std::cout << std::setw(w) << std::setprecision(4) << std::fixed << tablica[x][y];
		}
		std::cout << "   |  "<<sumaw[x]<<" ";
		std::cout << std::endl; 
	}
	std::cout << std::endl;
	for(int z=0; z<k; z++)
	{
		std::cout << std::setw(w)<< std::fixed <<sumak[z];
	}

	std::cout << "     Dziala :D" << std::endl;

	return 0;
}