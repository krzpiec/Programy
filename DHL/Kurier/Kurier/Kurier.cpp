// Kurier.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip> 
#include <vector>
//#include <vld.h>
#include "Funkcje.h"



int main()
{
	miasto * prootm = nullptr;	
	miasto * prootw = nullptr;
	std::string input = "Dane.txt";
	wczytaj(prootm, input);
	std::string output = "Droga.txt";
	std::string kolejnosc;
	int droga = 0;
	auto start = znajdz(prootm, 1);

	/*wypiszmiasta(prootm, 4);
	przenies(prootm, 5, prootw);
	std::cout << std::endl;
	std::cout << std::endl;
	wypiszmiasta(prootm, 4);

	auto zn = znajdz(prootm, 6);
	wypiszpol(zn->pkorzenpol, 4);*/

	algorytm(prootm, prootw, start, droga, kolejnosc);
	std::cout << "Droga: " <<droga<< std::endl;
	std::cout <<"Kolejnosc: "<< kolejnosc << std::endl;
	wpisz(output, droga, kolejnosc);

	//usundrzewomiast(prootw);
		

}
