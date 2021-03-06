// struktury.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// permutacja punktow

#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <cmath>
#include "Funkcje.h"

struct pkt
{
	double x;
	double y;
	double z;
};

struct indeks
{
	int i;
	int j;
	int k;
};

int main()
{
	int N = 10;
	
	int min = 1;
	int max = 10;

		std::vector<pkt> chmura = losuj(N, min, max);
		std::pair<pkt, pkt> para = para_odl(chmura);
		std::vector<indeks> koord(1); // zapisuje lokacje pktow tworzacych trojkat o najmn polu

		/*
		chmura[0] = {3,10,4};
		chmura[1] = {9,1,5};
		chmura[2] = {6,3,3};
		chmura[3] = {1,7,10};
		chmura[4] =	{9,2,1};
		*/

		std::cout << "Wspolrzedne punktow : " << std::endl;
		wypisz(std::cout, chmura);
		std::cout << std::endl;
		std::cout << najmpole(chmura, koord, min, max);
		std::cout << " --- najmniejsze pole";
		std::cout << std::endl;
		std::cout << kacik(chmura[koord[0].i], chmura[koord[0].j], chmura[koord[0].k]);
		std::cout << " -- kat miedzy dwoma krotszymi bokami";
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout<<plaszczyzna(chmura);
		std::cout << " -- plaszczyzna";
		std::cout << std::endl;
		std::cout << "Koniec programu";
	
 	return 0;
}
