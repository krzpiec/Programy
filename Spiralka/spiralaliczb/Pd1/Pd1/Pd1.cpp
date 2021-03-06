// Pd1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <iomanip>
int main()
{
	//Podaj liczbe  wierszy(w) i kolumn(k) o jeden wieksza niz bok kwadratu na ktorej jest opisana
	//Np dla spirali opisanej na kwadracie o boku 8 podaj w^k=9; bok =7 <==> w^k=8
	const int w = 11;
	const int k = 11;
	int a = 0;
	int b = 0;
	int c = 1;
	int tab[w][k] = { 0 };
	int pierwsze[w][k] = { 0 };
	int prawo = w; //kierunki obrotu spirali
	int lewo = w;
	int dol = k;
	int  gora = k - 1; //wynika z zakladanej figury podstawowej tak jak odejmowanie -2 od kierunkow
	int licznik = 0; //ilosc wykonanych figur podstawowych(uzyte dla przypadku boku o dlugosci 2n)
	//std::cout << "Tab | Koordynaty | c" << std::endl;

	while (gora > 0)
	{
		for (int i = 0; i < prawo; i++)
		{
			tab[a][b] = c;

			/*std::cout << tab[a][b];
			std::cout << " | Koordynaty:";
			std::cout << a;
			std::cout << ",";
			std::cout << b;
			std::cout << " | ";
			std::cout << c << std::endl;*/
			b++; c++;
		}
		prawo = prawo - 2;
		//std::cout << "Koniec prawo ";
		//std::cout << prawo << std::endl;
		b--;
		a++;

		for (int i = 1; i < dol; i++)
		{
			tab[a][b] = c;
			/*std::cout << tab[a][b];
			std::cout << " | Koordynaty:";
			std::cout << a;
			std::cout << ",";
			std::cout << b;
			std::cout << " | ";
			std::cout << c << std::endl;*/
			a++; c++;
		}
		dol = dol - 2;
		//std::cout << "Koniec dol ";
		//std::cout << dol << std::endl;
		a--;
		b--;

		for (int i = 1; i < lewo; i++)
		{
			tab[a][b] = c;
			/*std::cout << tab[a][b];
			std::cout << " | Koordynaty:";
			std::cout << a;
			std::cout << ",";
			std::cout << b;
			std::cout << " | ";
			std::cout << c << std::endl; */
			b--; c++;
		}
		lewo = lewo - 2;
		//	std::cout << "Koniec lewo ";
		//	std::cout << lewo << std::endl;
		b++;
		a--;

		for (int i = 1; i < gora; i++)
		{
			tab[a][b] = c;
			/*std::cout << tab[a][b];
			std::cout << " | Koordynaty:";
			std::cout << a;
			std::cout << ",";
			std::cout << b;
			std::cout << " | ";
			std::cout << c << std::endl; */
			a--; c++;
		}
		gora = gora - 2;
		//std::cout << "Koniec gora ";
		//std::cout << gora << std::endl;
		a++;
		b++;
		licznik++;
	}
	//std::cout <<"Ilosc fig podst "<< licznik <<" "<< std::endl;

	if (k % 2 == 1) { tab[licznik][licznik] = c; }
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < w; i++)
	{

		for (int f = 0; f < k; f++)
		{
			std::cout << std::setw(k) << tab[i][f];
		}
		std::cout << std::endl;
		std::cout << " " << std::endl;
	}
	int pierwsze[w + k] = { 0 };
	for (int i = 0; i < w; i++)
	{

		for (int f = 0; f < k; f++)
		{	
			int numer = i + f;
			pierwsze[numer] = tab[i][f];
		}
		std::cout << std::endl;
		std::cout << " " << std::endl;
	}

	return 0;
}

