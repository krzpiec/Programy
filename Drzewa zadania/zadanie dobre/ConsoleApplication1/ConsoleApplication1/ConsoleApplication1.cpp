// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "Funkcje.h"
#include <iomanip>

int main()
{
	wezel *proot1 = nullptr;
	wezel *proot2 = nullptr;
	for (typ i : { 5, 2, 8, 1, 0, 6, 3})
	{
		wypelnijit(proot1, i);
		//wypelnijrek(proot2, i);
	}
	wypisz(proot1, 1);
	odbij(proot1);
	std::cout << std::endl;
	wypisz(proot1, 1);
}
