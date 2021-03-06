// zad.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "Funkcje.h"

int main()
{
	element * phead = nullptr;
	element * ptail = nullptr;
	std::vector<int> liczby;
	int n = 10;

	wypelnij(liczby, n);

	for (auto i : liczby)///1,18,16,14,12,10,1,8,4,2,1
	{
		dodajnaKon(phead, ptail, i);
	}

	dodajnaKon(phead, ptail, 100);
	
	dodajdopos(phead, ptail, 101);

	//odwroc(phead, ptail);


	usunE(phead, 10);

	//////
	wypiszodpocz(phead);
	std::cout << std::endl;

	//
	wypiszodkon(ptail);
	std::cout << std::endl;
	/////

	element * phead2 = nullptr;
	element * ptail2 = nullptr;

	///////
	przenies(phead, phead2, ptail, ptail2, 1);
	wypiszodpocz(phead);
	std::cout << std::endl;
	wypiszodkon(ptail);
	std::cout << std::endl;
	///////
	wypiszodpocz(phead2);
	std::cout << std::endl;
	wypiszodkon(ptail2);
	/////
	usunliste(phead2, ptail2);
	wypiszodpocz(phead2);
	std::cout << std::endl;
	wypiszodkon(ptail2);

	sort(phead, ptail);
	//////
	std::cout << std::endl;
	wypiszodpocz(phead);
	std::cout << std::endl;
	wypiszodkon(ptail);
	std::cout << std::endl;
	//////

	ostnapocz(phead, ptail);
	std::cout << std::endl;
	wypiszodpocz(phead);
	std::cout << std::endl;
	wypiszodkon(ptail);
	std::cout << std::endl;
}