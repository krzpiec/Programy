// Egzamin 1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// Czas  czesci 1 : 45min 32s łacznie z testami i komentarzem
// Czas czesci 2: 1h 21 min :c

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Funkcje.h"
#include <vector>
#include <iomanip>


int main()
{
	
	int ktore = 0;
	std::cout << "Hetman = 0, Obraz != 0;";
	std::cin >> ktore;
	

		if (ktore == 0)
		{
			if (hetman("Szach.txt"))
				std::cout << "Mozna";
			else std::cout << "Niemozna";
		}
		else
		{
			int tab[W][K] = { 0 };
			wczytaj("Matrix.txt", tab);
			std::string wyjscie = "Matrix1.txt";
			zapisz(tab, wyjscie);
			przeksztalc("Matrix1.txt", "Wynik.txt");
		}
}

