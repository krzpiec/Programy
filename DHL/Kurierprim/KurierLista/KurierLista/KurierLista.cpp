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
	miasto * pHeadmiast = nullptr;
	miasto * pTailmiast = nullptr;
	
	std::string input = "Dane.txt";
	wczytaj(pHeadmiast, pTailmiast, input);
	wypiszmiasta(pHeadmiast);



		//wypiszmiasta(pHeadOdwiedzone);
		//wypiszmiasta(pHeadmiast);
	

	//wypiszmiasta(pHeadOdwiedzone);

	//wypiszodkon(pTailmiast);
	//auto p = pHeadmiast;
	//while (p)
	//{
	//	std::cout << "Start polaczenia dla: " << p->nazwa << std::endl;
	//	wypiszpol(p->pDrogi, 4);
	//	std::cout << std::endl;
	//	std::cout << "Koniec polaczen";
	//	std::cout << std::endl;
	//	std::cout << std::endl;
	//	p = p->pnext;
	//}
	//
}

