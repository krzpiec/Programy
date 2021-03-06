#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip> 
#include <vector>
#include <vld.h>
#include "Funkcje.h"


//Trasa dane.txt -> 
//1 - 7 - 5 - 4 - 2 - 1 || ZLA
// potem 1 - 7 - 3 - ... || ZLA
// potem 1 - 8 - 5 - 4 - 7 - ... || ZLA

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cerr << "Zle wywolany program" << std::endl;
		return -1;
	}

	std::string input = argv[1];
	std::string output = argv[2];
	std::cout << input;
	return 0;
	miasto * pHeadmiast = nullptr;
	miasto * pTailmiast = nullptr;
	miasto * pHeadOdwiedzone = nullptr;
	miasto * pTailOdwiedzone = nullptr;
	double PrzebytaDroga = 0;
	std::string input = "Dane.txt";
	std::string output = "Wyjscie.txt";
	bool wczytywanie = wczytaj(pHeadmiast, pTailmiast, input);
	miasto * Poprzednie = nullptr;
	miasto * Start = znajdzpoNazwie(pHeadmiast, 1);
	double przebytadroga = 0;

	if(wczytywanie)
		PrzyblizonaTrasaKuriera(przebytadroga,pHeadmiast, pTailmiast,Poprzednie,Start, pHeadOdwiedzone, pTailOdwiedzone, Start);
	else
	{
		std::cout << "Nie znaleziono pliku" << std::endl;
		return -1;
	}

	if (pHeadmiast)
	{
		std::cout << "Trasa niemozliwa do znalezienia" << std::endl;
		return 0;
	}

	PlikWyjsciowy(pHeadOdwiedzone, przebytadroga, output);

	usunwszystko(pHeadmiast, pTailmiast, pHeadOdwiedzone, pTailOdwiedzone);

	return 0;

}

