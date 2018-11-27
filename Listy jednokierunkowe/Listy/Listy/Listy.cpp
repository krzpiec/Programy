// Listy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
///visual sie na mnie obrazil i nie dziala .h i zrodlowy/////

typedef int typ;

struct element
{
	int wartosc;
	element* pnext;
};


void dodajIT(element *& pglowa, typ liczb)
{
	element * wstaw = new element;
	wstaw->wartosc = liczb;

	auto p = pglowa;
	while (p)
	{
		if (p->wartosc > wstaw->wartosc)
		{
			if (p == pglowa)
			{
				pglowa = new element{ liczb, pglowa };
				break;
			}
			else if (p->pnext->pnext == nullptr)
			{
				std::cout << p->wartosc << " Wartosc" << std::endl;
				auto temp = new element{ p->wartosc, p };
				p->pnext = temp;
				p->wartosc = liczb;

			}
			else if (p->pnext->wartosc > wstaw->wartosc)
			{	
				auto temp = new element{ liczb, p->pnext };
				p->pnext = temp;
				
				//	std::swap(temp->wartosc, p->wartosc);
					break;
			}
			
				
		}
		p = p->pnext;
	}

}


element * znajdzIT(element *& pglowa, typ liczba)
{
	auto p = pglowa;

	element * wstaw1 = new element{ liczba, nullptr };
	while (p)
	{
		if (p->wartosc == wstaw1->wartosc)
		{
			std::cout << p;
			break;
		}
		p = p->pnext;
	}
	return p;
}

void usun(element *& p, element* dous)
{
	int iterator = 0;
	auto glowa = p;
	while (p)
	{	
			if (p->pnext) 
			{
				if (glowa->pnext == dous)
				{
					element * pNastepnik = p->pnext;
					delete p;
					p = pNastepnik;
				}
				if (p->pnext == dous)
				{
					auto temp = p->pnext->pnext;
					delete p->pnext;
					p->pnext = temp;
				}

			}
			
			p = p->pnext;
		
		
	}
}

int main()
{
	element * pglowa = nullptr;

	////wypelniam liste
	for (int i : { 5, 5, 5, 5, 7, 8 ,9 })
	{
		if (not pglowa)
		{
			pglowa = new element{ i, nullptr };
		}

		else
		{
			element * pnowy = new element{ i, nullptr };
			auto p = pglowa;
			while (p->pnext)
				p = p->pnext;
			p->pnext = pnowy;
		}
	}
	///skonczylem wypelniac liste

	//////wstawianko

	typ liczb = 8;
	dodajIT(pglowa, liczb);
	std::cout << std::endl;
	///i po wstawianku

	///znajduje sobie liczbe
	
	//std::cout << znajdzIT(pglowa, liczba) << std::endl;;
	////// i znalezione
	element *wysw = pglowa;
	//aborcja liczby
	int liczba =8;
	element * abor = znajdzIT(pglowa, liczba);
	//usun(pglowa, abor);


	//i gotowe

	
	while (wysw)
	{
		std::cout << wysw->wartosc << " ";
		wysw = wysw->pnext;
	}
}
