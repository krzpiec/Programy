// lab8.cpp : Defines the entry point for the console application.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool hetman()
{

	std::ifstream plik;
	plik.open("Szach.txt", std::ios::in );
	if (!plik.good())
	{
		return false;
	}
	int  plansza[8][8] = { 0 };
	std::string wiersz;
	int iteracja = 0;
	/////zapelnianie tablicy
	while (getline(plik, wiersz))
	{
		for (int i = 0; i < wiersz.length(); i++)
		{
			if (wiersz[i] == '.')
				plansza[iteracja][i] = 0;
			else
				plansza[iteracja][i] = 1;
		}
		++iteracja;
	}

	//koniec zapelniania


	////// weryfikacja ////////

	//Petla dla wierszy
	for (int i = 0; i < 8; i++)
	{
		int sumaw = 0;//Czy ponowna deklaracja wyzeruje zmienna? chyba dziala
		int sumak = 0;
		for (int j = 0; j < 8; j++)
		{
			sumaw += plansza[i][j];
			sumak += plansza[j][i];
			if (sumaw > 1)
			{
				return false;
			}
		}//koniec pojedynczego wiersza/kolumny;
	}
	///////Koniec petli wierszy/kolumn

for (int i = 0; i < 8; i++)// dla kazdej krotkej przekatnej nad przekatnna DL-GP
{
int sumap=0;
int a = i;
int b = 0;
while (a >= 0)
{
sumap += plansza[a][b];
b ++;
a--;
if (sumap > 1)
return false;
}
}
for (int i = 6; i >= 0; i--)
{
int sumap = 0;
int a = i;
int b = 0;
while (a >= 0)
{
sumap += plansza[a][b];
b ++;
a--;
if (sumap > 1)
return false;
}
}



for (int i = 0; i < 8; i++)
{
	int sumap = 0;
	int a = 0;
	int b = i;
	while (b >= 0)
	{
		sumap += plansza[a][b];
		a ++;
		b--;
		if (sumap > 1)
			return false;
	}
}
for (int i = 6; i >= 0; i--)
{
	int sumap = 0;
	int b = i;
	int a = 0;
	while (b >= 0)
	{
		sumap += plansza[a][b];
		a ++;
		b--;
		if (sumap > 1)
			return false;
	}
}



	return true;
}
int main()
{
	if (hetman() == false)
	{
		std::cout << "Nie mozna" << std::endl;
	}
	else std::cout << "MNozna" << std::endl;
	return 0;
}