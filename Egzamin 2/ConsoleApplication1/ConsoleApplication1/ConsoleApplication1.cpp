
#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
//Start 0:32
//Zrobione w 42min - program dziala

struct pozycja
{
	int i;
	int j;
};

bool wczytaj(pozycja tab[64] , const std::string & nazwa)
{
	std::ifstream plik;
	plik.open(nazwa);
	if (not plik.good())
		return false;
	std::string linia;
	int temp = 0;
	int wiersz = 0;
	int kolumna = 0;

	while (std::getline(plik, linia))
	{
		std::stringstream ss(linia);
		while (ss)
		{
			if (ss >> temp)
			{
				tab[temp-1].i = wiersz;//temp-1 ze wzgledu na numerowanie tablic od 0
				tab[temp-1].j = kolumna;
				kolumna++;
				if (kolumna == 8)//koniec kolumny - kolejny wiersz
				{
					wiersz++;
					kolumna = 0;
				}
			}
		}
	
	}
	plik.close();
	return true;
}

bool sprawdzanie(pozycja tab[64])
{
	int warunek = 0;
	//petla wykonuje sie o 1 mniej niz liczba elementow w niej - porownuje element x z elementem x+1
	for (int iter=0; iter<63; iter++) //wszystkie permutacje przestrzennych ulozen litery L w tablicy-> jezeli znajdzie skok krola pasujacy - zwiekszy warunek
	{
		if (tab[iter].i - 2 == tab[iter + 1].i && tab[iter].j + 1 == tab[iter + 1].j)
			warunek++;
		if (tab[iter].i - 2 == tab[iter + 1].i && tab[iter].j - 1 == tab[iter + 1].j)
			warunek++;
		if (tab[iter].i - 1 == tab[iter + 1].i && tab[iter].j + 2 == tab[iter + 1].j)
			warunek++;
		if (tab[iter].i + 1 == tab[iter + 1].i && tab[iter].j + 2 == tab[iter + 1].j)
			warunek++;
		if (tab[iter].i + 2 == tab[iter + 1].i && tab[iter].j + 1 == tab[iter + 1].j)
			warunek++;
		if (tab[iter].i + 2 == tab[iter + 1].i && tab[iter].j - 1 == tab[iter + 1].j)
			warunek++;
		if (tab[iter].i - 1  == tab[iter + 1].i && tab[iter].j - 2 == tab[iter + 1].j)
			warunek++;
		if (tab[iter].i + 1 == tab[iter + 1].i && tab[iter].j - 2 == tab[iter + 1].j)
			warunek++;
		if (warunek == 0) return false; //brak pasujacego skoku -> niepoprawne ruchy
		
		warunek = 0; // zerowanie warunku do kolejnej iteracji
	}
	return true;
}

int main()
{
	pozycja tab[64] = { 0 };
	wczytaj(tab, "Dane.txt"); // W pliku zapisalem poprawne skoki
	bool ustawienie = sprawdzanie(tab);
	if (ustawienie)
		std::cout << "Poprawne";
	else
		std::cout << "Niepoprawne";

}
