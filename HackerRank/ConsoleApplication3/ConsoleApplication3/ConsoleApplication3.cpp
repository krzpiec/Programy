// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// Czas : 45min 32s łacznie z testami i komentarzem

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool hetman(const std::string& nazwa)
{	
	int tab[8][8] = { 0 };
	std::ifstream plik;
	plik.open(nazwa, std::ios::in);
	if (!plik.good())
	{
		std::cerr << "Nie ma pliku";
		return false;
	}
	std::string wiersz;
	int iterator = 0;
	while (getline(plik, wiersz))
	{
		for (int i = 0; i < wiersz.length(); i++)
		{
			if (wiersz[i] == '.') tab[iterator][i] = 0;
			else tab[iterator][i] = 1;
		}
		iterator++;
	}
	plik.close();
	//////Koniec wczytywaia////

	///Idea dzialania/////
	/// wczytuje hetmana jako 1, puste pola jako 0; jezeli suma kolmny/wiersza/przekatnej bedzie wieksza od 1 => 
	//ustawienie jest niepoprawne i funckja zwroci false, w przeciwnym wypadku przejdzie przez wszystkie petle i zwroci true;


	///Sprawdzanie wierszy///
	int sumaw = 0;
	int sumak = 0;
	
	for (int wiersze = 0; wiersze < 8; wiersze++)
	{
		sumaw = 0;
		sumak = 0;
		for (int kolumny = 0; kolumny < 8; kolumny++)
		{
			sumaw += tab[wiersze][kolumny];
			if (sumaw > 1)
			{
				std::cout << "Nawierszach";
				return false;
			}

			sumak += tab[kolumny][wiersze];
			if (sumak > 1) 
			{
				std::cout << "Na kolumnach";
				return false;
			}
		}
	}
	////Koniec wierszy i kolumn//////


	//Sprawdzanie przekatnych az od (0,0) do (7,0)|(0,7)
	int a = 0;
	int b = 0;
	int sumaprz = 0;
	for (int i = 1; i < 8; i++)
	{
		sumaprz = 0;
		a = i;
		b = 0;
		while (a >= 0)
		{
			sumaprz += tab[a][b];
			if (sumaprz > 1)
			{
				std::cout << "Na przekatnych1";
				std::cout << "NUmer:" << i;
				return false;
			}
			a--;
			b++;
		}
	}
	sumaprz = 0;
	//pierwsza czesc przekatnych skonczona

	///przekatne (7,1)|(1,7) do (7,7)
	for (int i = 6; i >= 0; i--)
	{
		sumaprz = 0;
		a = 7;
		b = 0;
			while (b <= 7)
			{
				sumaprz += tab[a][b];
				if (sumaprz > 1)
				{
					std::cout << "Na przekatnych 2";
					return false;
				}
				a--;
				b++;
			}
	}
	///Koniec przekatnych 2////

	/////Reverserd/////
	a = 0;
	b = 0;
	sumaprz = 0;
	for (int i = 0; i <8; ++i)
	{
		a = 7;
		b = i;
		sumaprz = 0;
		while (b>=0)
		{	
			sumaprz += tab[a][b];
			if (sumaprz > 1)
			{
				std::cout << "Na przekatnych 3";
				std::cout << i;
				return false;
			}
			a--;
			b--;
		}
	}
	////Koniec przekatnych 3;
	a = 0;
	b = 0;
	sumaprz = 0;

	for (int i = 6; i >= 0; --i)
	{
		b = 7;
		a = i;
		sumaprz = 0;
		while (a >= 0)
		{
			sumaprz += tab[a][b];
			if (sumaprz > 1)
			{
				std::cout << "Na przekatnych4";
				std::cout << i;
				return false;
			}
			a--;
			b--;
		}
	}


	return true;
}


int main()
{
	if(hetman("Szach.txt"))
		std::cout << "Mozna";
	else std::cout << "Niemozna";
}

