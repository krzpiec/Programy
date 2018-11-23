// Zad1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include "Funckje.h"
#include <sstream>


int main()
{	
	
	std::cout << std::endl;
	std::ofstream plik;
	plik.open("Macierz.txt");
	zapisz(plik);
	plik.close();
	
	std::ifstream odczyt;
	odczyt.open("Macierz.txt", std::ios::in);
	if (!odczyt)
	{
		std::cerr << "pliku nie znaleziono" << std::endl;
		return -1;
	}
	else {
			wypisz(odczyt, std::cout);
		 }
	std::cout << std::endl;
	odczyt.close();
	
	odczyt.open("Macierz.txt", std::ios::in);
	std::cout<<"Srednia wszystkich wierszy: " <<srednia(odczyt)<<std::endl;
	odczyt.close();
	
	odczyt.open("Macierz.txt", std::ios::in);
	srednia_w(odczyt, std::cout);
	odczyt.close();

	odczyt.open("Macierz.txt", std::ios::in);
	double frob = 0;
	std::cout << "Norma frobeniusa: ";
	std::cout<<frobenius(odczyt, frob)<<std::endl;
	odczyt.close();

	std::cout << std::endl;
	
	odczyt.open("Macierz.txt", std::ios::in);
	std::cout << "Macierz bez powtorzen: ";
	std::cout << std::endl;
	uniq(odczyt, std::cout);
	odczyt.close();
	std::cout << std::endl;

	std::ifstream odczyt1;
	odczyt1.open("Macierz.txt", std::ios::in);
	std::cout << "Transponowana macierz: ";
	std::cout << std::endl;
	transponuj(odczyt1, std::cout);
	std::cout << std::endl;
	
	std::ofstream tekst;
	tekst.open("Tekst.txt");
	tekst << "Czy to zadziala";
	tekst.close();
	
	
	std::ifstream spacje;
	spacje.open("Tekst.txt", std::ios::in);
	pierwsze(spacje, std::cout);
	spacje.close();

	std::cout << std::endl;
	std::string tekst1 = "Chyba powinienem uzyc stringstream ale nie umiem to robie tak";
	rozdziel(tekst1);
	return 0;
}
