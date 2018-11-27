
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "Funkcje.h"
#include <iomanip>


bool hetman (const std::string& nazwa)
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
				std::cout << "Na wierszach";
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
				std::cout << "Na przekatnych 1";
				return false;
			}
			a--;
			b++;
		}
	}
	sumaprz = 0;
	//pierwsza czesc przekatnych skonczona

	///przekatne (7,1)|(1,7) do (7,7)
	for (int i = 0; i <7; i++)
	{
		sumaprz = 0;
		a = 7;
		b = i;
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
	for (int i = 0; i < 8; ++i)
	{
		a = 7;
		b = i;
		sumaprz = 0;
		while (b >= 0)
		{
			sumaprz += tab[a][b];
			if (sumaprz > 1)
			{
				std::cout << "Na przekatnych 3";
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
				std::cout << "Na przekatnych 4";
				return false;
			}
			a--;
			b--;
		}
	}
	// koniec przekatnych 4

	return true;
}

void wczytaj (const std::string& nazwa, int tab[W][K])

{
	std::ifstream s;
	s.open(nazwa, std::ios::in);
	if (!s.good())
	{
		std::cerr << "Nie odnaleziono pliku obrazu" << std::endl;
		exit(0);//nie wolno ale nie wiem jak zakonczyc, a pisac reszte funkcji w else dziwnie
	}

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			s >> tab[i][j];
		}
	//wczytuje do tablicy;
	}
	s.close();
}

void zapisz(int tab[W][K], const std::string& nazwa )
{
	std::ofstream plik;
	plik.open(nazwa, std::ios::out);
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			plik << tab[i][j] << " ";
		}
		plik << std::endl;
	}
	plik.close();
}

void przeksztalc(const std::string& wejscie, const std::string& wyjscie)
{
	int tab[W][K] = { 0 };
	int result[W][K] = { 0 };
	wczytaj(wejscie, tab);
	int suma = 0;
	int podzielnik = 0;
	//Dla pozycji (i,j) sasiedzi maja wspolrzedne (i-1,j), (i-1,j+1), (i,j+1), (i+1,j+1), (i+1,j), (i+1,j-1), (i,j-1), (i-1,j+1)
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K;j++)
		{
			suma += tab[i][j];
			podzielnik++;
			if (j + 1 < K)
			{
				suma += tab[i][j + 1];
				podzielnik++;
				if (i + 1 < W)
				{
					suma += tab[i + 1][j + 1];
					podzielnik++;
				}
				if (i - 1 >= 0)
				{
					suma += tab[i - 1][j + 1];
					podzielnik++;
				}
			
			}
			if (i - 1 >= 0)
			{
				suma += tab[i - 1][j];
				podzielnik++;
				if (j - 1 >= 0)
				{
					suma += tab[i - 1][j - 1];
					podzielnik++;
				}
			}
			if (i + 1 < W)
			{
				suma += tab[i + 1][j];
				podzielnik++;
				if (j - 1 >= 0)
				{
					suma += tab[i + 1][j - 1];
					podzielnik++;
				}
			}
			if (j - 1 >= 0)
			{
				suma += tab[i][j - 1];
				podzielnik++;
			}
			result[i][j] = (int)suma / podzielnik;
				suma = 0;
			podzielnik = 0;
		}
	}

	std::ofstream out;
	out.open(wyjscie);
	if (!out.good())
	{
		std::cerr << "Nie odnaleziono pliku";
		exit(0);
	}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			out << std::setw(5) << result[i][j];
		}
		out << std::endl;
	}
	out.close();
}