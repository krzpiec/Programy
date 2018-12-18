#include "pch.h"
#include <iostream>
#include "Funkcje.h"
#include <iomanip>

void wypisz(wezel * pRoot, int wciecie)
{
	const int MNOZNIK = 4;
	if (pRoot)  // jezeli drzewo jest niepuste
	{
		wypisz(pRoot->lewy, wciecie + 1);
		std::cout << std::setw(wciecie * MNOZNIK) << pRoot->data << std::endl;
		wypisz(pRoot->prawy, wciecie + 1);
	}

}

void wypelnijrek(wezel * & proot, const typ data)
{
	if (not proot)
		proot = new wezel{ data, nullptr, nullptr };
	else
	{
		if (data >= proot->data)
			wypelnijrek(proot->prawy, data);
		else
			wypelnijrek(proot->lewy, data);
	}
}

void wypelnijit(wezel * & proot, typ wart)
{
	if (not proot)
		proot = new wezel{ wart, 0, 0 };
	else // w drzewie juz cos jest 
	{
		auto p = proot;

		while (p)
		{
			if (wart < p->data) // idziemy w lewo
			{
				if (p->lewy)  // jezeli istnieje pLewy
					p = p->lewy;
				else
				{
					p->lewy = new wezel{ wart, 0, 0 };
					p = nullptr; // mo¿na daæ return;
//                     return;
				}
			}
			else  // idziemy w prawo
			{
				if (p->prawy)
					p = p->prawy;
				else
				{
					p->prawy = new wezel{ wart, 0, 0 };
					p = nullptr; // mo¿na daæ return;
//                     return;
				}
			}
		}
	}
}

void odbij(wezel *proot)
{
	if ((not proot->lewy and not proot->prawy)   )
		return;
	else
	{
		std::swap(proot->prawy, proot->lewy);
		odbij(proot->prawy);
	}
}

void wypiszwszerz(wezel *proot)
{

}