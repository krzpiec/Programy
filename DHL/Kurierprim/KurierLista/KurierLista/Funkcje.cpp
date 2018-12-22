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

void dodajmiastojakoelement(miasto *& pHeadOdwiedzone, miasto *& pTailOdwiedzone, miasto *& kopiamiasta, polaczenia *& kopiadrog)
{
	
	if (not pHeadOdwiedzone)
	{
		pHeadOdwiedzone = kopiamiasta;
		pHeadOdwiedzone->pnext = nullptr;
		pHeadOdwiedzone->pprev = nullptr;
		pHeadOdwiedzone->pDrogi = kopiadrog;
		pTailOdwiedzone = pHeadOdwiedzone;
		return;
	}
	
	kopiamiasta->pprev = pTailOdwiedzone;
	kopiamiasta->pnext = nullptr;
	pTailOdwiedzone->pnext = kopiamiasta;
	pTailOdwiedzone = kopiamiasta;
	return;
}

bool wczytaj(miasto *& pHeadmiast, miasto *& pTailmiast, const std::string & nazwa)
{
	std::ifstream plik;
	plik.open(nazwa);
	if (not plik.good())
	{
		return false;
	}
	std::string linia;

	int licz = 0;
	int skad = 0;
	int dokad = 0;
	int droga = 0;
	std::string del = "()->,:";
	while (std::getline(plik, linia))
	{
		for (int i = 0; i < del.length(); i++)
		{
			size_t pos = linia.find(del[i]); // linia.find_first_of (del);
			if (pos != std::string::npos)
				linia.replace(linia.begin() + pos, linia.begin() + pos + 1, " ");
		}
		//std::cout << linia << std::endl;
		std::stringstream ss(linia);

		double temp = 0;
		while (ss)
		{
			if (ss >> temp)
			{
				switch (licz)
				{
				case 0:
				{
					skad = temp;
					licz++;
					break;
				}
				case 1:
				{
					dokad = temp;
					licz++;
					break;
				}
				case 2:
				{
					droga = temp;
					licz = 0;
					dodajdomiast(pHeadmiast, pTailmiast, skad, dokad, droga);
					break;
				}

				}
			}
		}
	}
	plik.close();
	return true;
}

void dodajdopol(polaczenia *& pkorzen, const int dokad, const double droga)
{

	if (not pkorzen)//drzewo polaczen jest puste
		pkorzen = new polaczenia{ dokad ,droga , 0, 0, 0 };

	else // w drzewie polaczen juz cos jest 
	{
		auto p = pkorzen;

		while (p)
		{

			if (droga < p->droga) // idziemy w lewo
			{
				if (p->plewy)  // jezeli istnieje pLewy
					p = p->plewy;
				else
				{
					p->plewy = new polaczenia{ dokad,droga ,  0, 0 ,p };
					p = nullptr;
				}
			}
			else  // idziemy w prawo
			{
				if (p->pprawy)
					p = p->pprawy;
				else
				{
					p->pprawy = new polaczenia{ dokad,droga ,  0, 0 ,p };
					p = nullptr;
				}
			}
		}
	}
}

void dodajdomiast(miasto *& pHeadmiast, miasto *& pTailmiast,  const int skad, const int dokad, const double droga)
{
	if (not pHeadmiast)//Lista jest pusta
	{
		pHeadmiast = new miasto{ skad,false, 0 , 0 , 0 }; 
		pTailmiast = pHeadmiast;
		dodajdopol(pHeadmiast->pDrogi, dokad, droga);
		return;
	}
	miasto * p = pHeadmiast;
	while (p)
	{
		if (p->nazwa == skad)
		{
			dodajdopol(p->pDrogi, dokad, droga);
			return;
		}
		p = p->pnext;
	}

		auto temp = pTailmiast;

		auto wstaw = new miasto{ skad,false,  0,0, pTailmiast };
		pTailmiast->pnext = wstaw;
		pTailmiast = wstaw;
		dodajdopol(pTailmiast->pDrogi, dokad, droga);
	
}

bool wypiszmiasta(miasto * pHeadmiast)
{
	if (not pHeadmiast)
	{
		std::cout << "Lista jest pusta";
		return false;
	}

	std::cout << "START" << std::endl;
	while (pHeadmiast)
	{
		std::cout << pHeadmiast->nazwa << " ";
		pHeadmiast = pHeadmiast->pnext;
	}
	std::cout << std::endl;
	std::cout << "STOP" << std::endl;
	return true;
}

miasto * znajdzpoNazwie(miasto * pHeadmiast, const int nazwa)
{
	if (pHeadmiast == nullptr) //lista pusta 
		return pHeadmiast;
	while (pHeadmiast)
	{
		if (pHeadmiast->nazwa == nazwa)
			return pHeadmiast;
		pHeadmiast = pHeadmiast->pnext;
	}
	return nullptr; //nie znaleziono
}

bool znajdzpoAdresie(miasto * pHeadmiast, miasto * szukana)
{
	if (not pHeadmiast)
	{
		return false;
	}
	auto p = pHeadmiast;
	while (p)
	{
		if (p == szukana)
			return true;
		p = p->pnext;
	}
	return false;
}

void wypiszpol(polaczenia * proot, int wciecie)
{
	const int MNOZNIK = 4;
	if (proot)  // jezeli drzewo jest niepuste
	{
		wypiszpol(proot->plewy, wciecie + 1);
		std::cout << std::setw(wciecie * MNOZNIK) << proot->dokad << "-" << proot->droga << std::endl;
		wypiszpol(proot->pprawy, wciecie + 1);
	}
}

void usunMiasto(miasto *& pHeadmiast, miasto *& pTailmiast, miasto * dousuniecia) 
{
	if (not pHeadmiast)
	{
		return;
	}

	if (pHeadmiast == dousuniecia)
	{
		auto temp = pHeadmiast->pnext;
	//	usundrzewopol(pHeadmiast->pDrogi);
		//delete pHeadmiast;
		//temp->pprev = nullptr;
		pHeadmiast = temp;
		return;
	}
	if (pTailmiast == dousuniecia)
	{
		auto temp = pTailmiast->pprev;
		//usundrzewopol(pTailmiast->pDrogi);
		//delete pTailmiast;
		//temp->pnext = nullptr;
		pTailmiast = temp;
		return;
	}
	auto temp = pHeadmiast;
	while (temp->pnext != nullptr && temp->pnext != dousuniecia)
		temp = temp->pnext;

	if (temp->pnext == nullptr)
		return;


	if (temp->pnext == dousuniecia)
	{
		auto p = temp->pnext->pnext;
		//usundrzewopol(temp->pnext->pDrogi);
		//delete temp->pnext;
		temp->pnext = p;
		p->pprev = temp;
		return;
	}
}

void usundrzewopol(polaczenia *& pDrogi)
{
	if (pDrogi)
	{
		usundrzewopol(pDrogi->plewy);
		usundrzewopol(pDrogi->pprawy);

		delete pDrogi;
		pDrogi = nullptr;
	}
}

void wypiszodkon(miasto * ptail)
{
	if (ptail == nullptr)
	{
		std::cout << "Lista jest pusta";
		return;
	}

	std::cout << "START" << std::endl;
	while (ptail)
	{
		std::cout << ptail->nazwa << " ";
		ptail = ptail->pprev;
	}
	std::cout << std::endl;
	std::cout << "STOP" << std::endl;
}

void przenies(miasto *& pHeadmiast, miasto *& pTailmiast, miasto *& pHeadOdwiedzone, miasto *& pTailOdwiedzone, miasto * doprzeniesienia)
{
	if (not pHeadmiast)
		return;
	miasto *p = pHeadmiast;
	while (p)
	{
		if (p == doprzeniesienia)
		{
			usunMiasto(pHeadmiast, pTailmiast, p);
			dodajmiastojakoelement(pHeadOdwiedzone, pTailOdwiedzone, p, p->pDrogi);
			
			return;
		}
		p = p->pnext;
	}
}

miasto *NajblizszeMiasto(polaczenia *pDrogi, miasto * pHeadmiast)
{
	if (not pDrogi || pDrogi->dokad->odwiedzone)
		return nullptr;
	if (not pDrogi->plewy)
	{
		if (not pDrogi->odwiedzone) //NIE odwiedzone
		{
			pDrogi->odwiedzone == true;
			return znajdzpoNazwie(pHeadmiast, pDrogi->dokad);
		}

	}
		
	while (pDrogi->plewy && not pDrogi->plewy->odwiedzone)
		pDrogi = pDrogi->plewy;

	pDrogi->odwiedzone == true;
	return znajdzpoNazwie(pHeadmiast, pDrogi->dokad);
}
	
void PrzyblizonaTrasaKuriera(miasto *& pHeadmiast, miasto *& pTailmiast, miasto *& Poprzednie, miasto *& Aktualne, miasto *& pHeadOdwiedzone, miasto *& pTailOdwiedzone, double & PrzebytaDroga)
{
	while (pHeadmiast)
	{
		miasto* Krok = NajblizszeMiasto(Aktualne->pDrogi, pHeadmiast);
		if (not Krok)
		{
			Aktualne->od
		}
	}


}