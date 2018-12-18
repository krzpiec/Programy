#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "Funkcje.h"

void wypelnij(std::vector<int>& liczby, const int n)/// wypelnia wektor pseudolos liczbami
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> numb(1, 1000);
	for (int i = 0; i < n; i++)
	{
		int p = numb(silnik);
		liczby.push_back(p);
	}
}

void dodajnaPocz(element * & phead, element * & ptail, const typ wart)
{
	if (!phead)//lista jest pusta
	{
		phead = new element{ wart,  0, 0 };
		ptail = phead;
	}
	else // cos jest
	{
		auto temp = phead;
		phead = new element{ wart , temp, nullptr };
		temp->pprev = phead;
	}
}

void wypiszodpocz(element * phead)
{
	if (phead == nullptr)
	{
		std::cout << "Lista jest pusta";
		return;
	}
	auto temp = phead;
	std::cout << "START" << std::endl;

	while (temp)
	{
		std::cout << temp->wartosc <<" ";
		temp = temp->pnext;
	}
	std::cout << std::endl;
	std::cout << "STOP" << std::endl;
}

void wypiszodkon(element * ptail)
{
	if (ptail == nullptr)
	{
		std::cout << "Lista jest pusta";
		return;
	}
		
	std::cout << "START" << std::endl;
	while (ptail)
	{
		std::cout << ptail->wartosc << " ";
		ptail = ptail->pprev;
	}
	std::cout << std::endl;
	std::cout << "STOP" << std::endl;
}

void dodajnaKon(element * & phead, element * & ptail, const typ wart)
{
	if (!phead)//lista jest pusta
	{
		phead = new element{ wart,  0, 0 };
		ptail = phead;
	}
	else // cos jest
	{
		auto temp = ptail;
	
		auto wstaw = new element{ wart, 0, ptail };
		ptail->pnext = wstaw;
		ptail = wstaw;

	}
}

void dodajdopos(element * & phead, element * & ptail, const typ wart)
{
	auto p = phead;
	if (!phead || phead->wartosc > wart)//jezeli lista jest pusta lub wstawic przed pierwsza watosc
	{
		dodajnaPocz(phead, ptail, wart);
	}

	else
	{
		while ((p->pnext != nullptr) && (p->pnext->wartosc < wart)) //dopóki nie wyjde z listy lub nie znajde elementu na nastepnej pozycji
			p = p->pnext;

		if (p->pnext == nullptr) //wstawiam na koniec
		{
			auto nowy = new element{ wart, nullptr, p };
			p->pnext = nowy;
			ptail = nowy;
		}
		else // wstawiam w srodku
		{
			auto nowy = new element{ wart, p->pnext ,p };
			p->pnext = nowy;
			nowy->pnext->pprev = nowy;
		}
	}
}

void odwroc(element * & phead, element * & ptail)
{
	if (phead == nullptr)//lista jest pusta
		return;
	auto ph = phead;
	auto pt = phead;
	while (pt) //zamieniam wskazniki next z prev i prev z next, phead i ptail zostaja zamienione oddzielnie
	{	
		ph = pt; //ph->pnext ulega zmianie, wiec aby przesuwac sie dobrze w przod
		auto temp = ph->pnext;
		if (ph != phead && ph != ptail)
		{
			
			ph->pnext = ph->pprev;
			ph->pprev = temp;
		}
		pt = temp; 
	}
	//zamieniam phead z ptail, przy czym potrzebna jest koretka -> ptail mial wartosc w pprev, a phead potrzebuje w pnext, i odwrotnie

	auto temp = phead;//phead ulega zmianie, a ptail potrzebuje phead w oryginalnej wersji

	//zamiana phead
	phead = ptail; 
	auto t1 = phead;
	phead->pnext = phead->pprev;
	phead->pprev = nullptr;
	//koniec phead

	//zamiana ptail
	auto t2 = ptail;
	ptail = temp;
	ptail->pprev = ptail->pnext;
	ptail->pnext = nullptr;
	//koniec ptail
}

element *znajdz(element *phead, const typ wart)
{
	if (phead == nullptr) //lista pusta 
		return phead;
	while (phead)
	{
		if (phead->wartosc == wart)
		return phead;
		phead = phead->pnext;
	}
	return nullptr; //nie znaleziono
}

void usunE(element *& phead, const typ wart) //funckja dodana na potrzeby f.przenies
{
	if (phead == nullptr)//lista pusta
		return;
	 if (phead->wartosc == wart) //pierwszy elemnent to szukana 
	 {
		element * pk = phead->pnext;
		auto result = phead;
		delete phead;
		phead = pk;
		phead->pprev = nullptr;
		return;
	}
	auto temp = phead;
	while (temp->pnext != nullptr && temp->pnext->wartosc != wart) //koniec albo jak wyjde za liste albo jak znajde szukana w nastepnym elemencie
		temp = temp->pnext;

	if (temp->pnext == nullptr) //jezeli poza lista
		return;
	if(temp->pnext->wartosc == wart) //jezeli znaleziono
	{
		auto p = temp->pnext->pnext;
		auto pp = temp->pnext->pprev;
		auto result = temp->pnext;
		delete temp->pnext;
		temp->pnext = p;
		temp->pnext->pprev = pp;
		return;
	}
}

void przenies(element *& pheadwej, element *& pheadwyj, element *& ptailwej, element *& ptailwyj, const typ wart)
{
	if (pheadwej == nullptr) //pusto
		return;
	int licz = 0;
	auto ph = pheadwej;
		while (ph) //ilosc elementow w liscie
		{
			licz++;
			ph = ph->pnext;
		}
		int iter = 0;
		auto phprim = pheadwej;
		while (iter==0) //dziwnie dzialajaca petla, ale dzialajaca
		{
			auto temp = znajdz(pheadwej, wart); 
			if (temp != nullptr) // jezeli znaleziono element to od razu go usunieto
			{
				usunE(pheadwej, wart);
				dodajnaPocz(pheadwyj, ptailwyj, wart); // dodajemy do listy 2
			}
			else
				break;
		}
}

void usunliste(element *& phead, element *& ptail)
{
		while (phead)
		{
			element * temp = phead->pnext;
			delete phead;
			phead = temp;
		}
		ptail = nullptr;
}

void sort(element *& phead, element *& ptail)
{
	auto ph = phead;
	for (ph; ph != nullptr; ph=ph->pnext)
	{
		for (auto j = phead; j!= nullptr; j=j->pnext)
		{
			if (ph->wartosc < j->wartosc)
				std::swap(ph->wartosc, j->wartosc);
		}
	}
}

void ostnapocz(element *& phead, element *& ptail)
{
	const typ temp = ptail->wartosc;
	auto pt = ptail->pprev;
	delete ptail;
	ptail = pt;
	ptail->pnext = nullptr;
	dodajnaPocz(phead, ptail, temp);
}