#include "pch.h"
#include <iostream>
#include "Funkcje.h"

void dodajnaPocz(element *& phead, const typ wart)
{
	phead = new element{wart,phead };
}

void wypisz(element *phead)
{
	std::cout << "START" << std::endl;
	while (phead)
	{
		std::cout << phead->wartosc << " ";
		phead = phead->pnext;
	}
	std::cout << std::endl;
	std::cout <<"STOP"<< std::endl;
	std::cout << std::endl;
}

void dodajnaKon(element *& phead, const typ wart)
{
	if (!phead)
	{
		dodajnaPocz(phead, wart);
	}
	else
	{
		auto temp = phead;
		while (temp->pnext != nullptr)
			temp = temp->pnext;
		temp->pnext = new element{ wart, nullptr };
	}
	
}

void wypelnij(element *& pglowa, const typ wart)
{
	if (not pglowa)
	{
		pglowa = new element{ wart, nullptr };
	}

	else
	{
		element * pnowy = new element{ wart, nullptr };
		auto p = pglowa;
		while (p->pnext)
			p = p->pnext;
		p->pnext = pnowy;
	}
}

void dodajIT(element *& phead, typ wart)
{
	auto p = phead;
	if (!phead || phead->wartosc > wart)//jezeli lista jest pusta lub wstawic przed pierwsza watosc
	{
		dodajnaPocz(phead, wart);
	}

	else
	{
		while ((p->pnext != nullptr) && (p->pnext->wartosc < wart)) //dopóki nie wyjde z listy lub nie znajde elementu
			p = p->pnext;

		if (p->pnext == nullptr) //wstawiam na koniec
		{
			auto nowy = new element{ wart, nullptr};
			p->pnext = nowy;
		}
		else // wstawiam w srodku
		{
			auto nowy = new element{ wart, p->pnext };
			p->pnext = nowy;
			
		}
	}
	}

element * znajdzIT(element *& phead, typ liczba)
{
	if(phead==nullptr)
		return nullptr;
	auto p = phead;
	while (p)
	{
		if (p->wartosc == liczba)
		{
			return p;
		}
		p = p->pnext;
	}
	return nullptr;
}

void usunE(element *& phead, const typ wart)
{
	if (phead == nullptr)
	{
		return;
	}

	if (phead->wartosc == wart)
	{
		element * pkolejny = phead->pnext;
		delete phead;
		phead = pkolejny;
		return;
	}

	else
	{
		auto p = phead;
		while ((p->pnext != nullptr) && (p->pnext->wartosc!=wart))
			p = p->pnext;

		auto temp = p->pnext->pnext;
		delete p->pnext;
		p->pnext = temp;
	}
}

void usunAdr(element *& phead, element *& dous)
{
	if (phead == nullptr)
	{
		return;
	}

	if (phead == dous)
	{
		element * pkolejny = phead->pnext;
		delete phead;
		phead = pkolejny;
		return;
	}

	else
	{
		auto p = phead;
		while ((p->pnext != nullptr) && (p->pnext != dous))
			p = p->pnext;

		auto temp = p->pnext->pnext;
		delete p->pnext;
		p->pnext = temp;
	}
}

void usunElementy(element *& phead, const typ wart)
{
	if (phead == nullptr)
	{
		return;
	}
	auto temp = znajdzIT(phead, wart);
	if (temp == nullptr) return;
	while (temp != nullptr)
	{
		usunAdr(phead, temp);
		temp = znajdzIT(phead, wart);
	}
	
}

void odwroc(element *& phead)
{
	if (!phead || phead->pnext == nullptr)
		return;
	element *prev = nullptr;
	element *curr = phead;
	element* next;
	while (curr != nullptr)
	{
		next = curr->pnext;
		curr->pnext = prev;
		prev = curr;
		curr = next;
	}
	phead = prev;
}

void powtorzenia (element *& phead)
{
	if (phead == nullptr||phead->pnext==nullptr)
		return;
	element *iter = new element{ 0,0 };
	auto ph = phead;
	while (ph)
	{
		iter = ph;
		while (iter->pnext)
			if (iter->pnext->wartosc == ph->wartosc)
			{
				usunAdr(phead, iter->pnext);
			}
			else iter = iter->pnext;
		ph = ph->pnext;
	}
}

element *iloMno(element * ph1, element * ph2)
{
	if (ph1 == nullptr || ph2 == nullptr)
		return nullptr;
	element *phmno = nullptr;
	while (ph1)
	{
		if (znajdzIT(ph2, ph1->wartosc) != nullptr) dodajnaKon(phmno, ph1->wartosc);
		ph1 = ph1->pnext;
	}
	return phmno;
}

element *sumaMno(element * ph1, element * ph2)
{
	element *phmno = nullptr;
	if (ph1 == nullptr)
	{
		phmno = ph2;
		return phmno;
	}
	if (ph2 == nullptr)
	{
		phmno = ph1;
		return phmno;
	}
	while (ph1)
	{
		dodajnaKon(phmno, ph1->wartosc);
		ph1 = ph1->pnext;
	}
	while (ph2)
	{
		dodajnaKon(phmno, ph2->wartosc);
		ph2 = ph2->pnext;
	}
	powtorzenia(phmno);
	return phmno;
	
}

element *rozMno(element * ph1, element * ph2)
{
	element *phmno = nullptr;
	if (ph1 == nullptr)
	{
		return phmno;
	}
	if (ph2 == nullptr)
	{
		phmno = ph1;
		return phmno;
	}
	while (ph1)
	{
		if (znajdzIT(ph2, ph1->wartosc) == nullptr)
			dodajnaKon(phmno, ph1->wartosc);

		ph1 = ph1->pnext;
	}
	return phmno;
}

void usunparz(element *& phead)
{
	if (phead == nullptr)
		return;

	if (phead->wartosc%2==0)
	{
		element * pkolejny = phead->pnext;
		delete phead;
		phead = pkolejny;
		return;
	}
	else
	{
		auto ph = phead;
		while (ph->pnext != nullptr)
		{
			if (ph->pnext->wartosc % 2 == 0)
				usunAdr(phead, ph->pnext);
			else
				ph = ph->pnext;
		}
	}
	
}

void usunost(element *& phead)
{
	if (phead == nullptr)
		return;
	if (phead->pnext == nullptr)
	{
		usunAdr(phead, phead);
	}
	element *ph = phead;
	while (ph->pnext)
		ph = ph->pnext;
	usunAdr(phead, ph);
}

element * scal(element * ph1, element * ph2)
{
	element *scalone = nullptr;
	while (ph2)
	{
		dodajIT(scalone, ph2->wartosc);
		ph2 = ph2->pnext;
	}
	while (ph1)
	{
		dodajIT(scalone, ph1->wartosc);
		ph1 = ph1->pnext;
	}
	return scalone;
}

void sortuj(element *& phead)
{
	if (phead == nullptr || phead->pnext == nullptr)
		return;
	element *ph = phead;
	for (ph; ph->pnext != nullptr; ph = ph->pnext)
	{
		for (auto j = ph; j != nullptr; j = j->pnext)
		{
			if (ph->wartosc > j->wartosc)
				std::swap(ph->wartosc, j->wartosc);
		}
	}
}

std::pair<typ, typ> exmin(element * phead)
{
	std::pair<typ, typ> result;
	if (phead == nullptr)
	{
		result.first = 0;
		result.second = 0;
		std::cout << "Lista jest pusta!" << std::endl;
		return result;
	}
	if (phead->pnext == nullptr)
	{
		result.first = phead->wartosc;
		result.second = phead->wartosc;
		return result;
	}
	
	auto temp = phead;
	typ max = phead->wartosc;
	typ min = phead->wartosc;
	phead = phead->pnext;
	while (phead)
	{
		if (phead->wartosc > max)
			max = phead->wartosc;
		if (phead->wartosc < min)
			min = phead->wartosc;
		phead = phead->pnext;
	}
	result.first = min;
	result.second = max;
	return result;
}

element *listatodele(element *phead, element *&ten)
{
	element * res = nullptr;
	while (phead != ten)
		phead = phead->pnext;
	while (phead)
	{
		dodajnaKon(res, phead->wartosc);
		phead = phead->pnext;
	}
	return res;
}

element *listaodwart(element *phead, const typ wart)
{
	element * res = nullptr;
	if (phead == nullptr)
		return nullptr;
	if (phead->wartosc == wart)
	{
		return phead;
	}
	auto ph = phead;
	while ((ph != nullptr) && (ph->wartosc != wart)) 
		ph = ph->pnext;
	if (ph == nullptr)
		return nullptr;
	else
	{
		while (ph)
		{
			dodajnaKon(res, ph->wartosc);
			ph = ph->pnext;
		}
	}
	return res;
}

void przesun(element*&phead)
{
	auto ph = phead;
	while (ph->pnext)
		ph = ph->pnext;
	typ temp = ph->wartosc;
	usunAdr(phead,ph);
	dodajnaPocz(phead, temp);
}

void usunliste(element *& phead)
{
	while (phead)
	{
		usunAdr(phead, phead);
	}
}