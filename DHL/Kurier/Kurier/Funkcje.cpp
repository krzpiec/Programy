
#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <vld.h>
#include "Funkcje.h"


void usundrzewopol(polaczenia *prootpol)
{
	if (prootpol)
	{
		usundrzewopol(prootpol->plewy);
		usundrzewopol(prootpol->pprawy);

		delete prootpol;
		prootpol = nullptr;
	}
}

void usundrzewomiast(miasto *prootm)
{
	if (prootm)
	{
		usundrzewopol(prootm->plewy->pkorzenpol);
		usundrzewomiast(prootm->plewy);
		usundrzewopol(prootm->pprawy->pkorzenpol);
		usundrzewomiast(prootm->pprawy);

		usundrzewopol(prootm->pkorzenpol);
		delete prootm;
		prootm = nullptr;
	}
}

void dodajdomiastwynik(miasto *& prootw, const int nazwa, polaczenia *& polacz)
{

	if (not prootw) // drzewo puste
		prootw = new miasto {nazwa, polacz, nullptr, nullptr, nullptr };
	else  // w drzewie juz co jest
	{
		auto p = prootw;
		while (p)
		{

			if (nazwa< p->nazwa) //  w lewo
			{
				if (p->plewy)  // jezeli mozna isc w lewo
					p = p->plewy;
				else
				{	
					p->plewy = new miasto{ nazwa, polacz, nullptr, nullptr, p };
					return;
				}
			}
			else   // w prawo
			{
				if (p->pprawy)  // jezeli mozna isc w lewo
					p = p->pprawy;
				else
				{
					p->pprawy = new miasto{ nazwa, polacz, nullptr, nullptr, p };
					return;
				}
			}

		}
	}
}

void dodajdomiast(miasto *& prootm, const int skad, const int dokad, const double droga)
{
	if (not prootm) ///drzewo miast jest puste
	{
		prootm = new miasto{ skad,0 , 0 , 0, 0 };
		dodajdopol(prootm->pkorzenpol, dokad, droga);
	}
	else // w drzewie miast juz cos jest 
	{
		auto p = prootm;

		while (p)
		{
			
			 if (skad < p->nazwa) //  w lewo
			{
				if (p->plewy)  // jezeli mozna isc w lewo
					p = p->plewy;
				else 
				{
					p->plewy = new miasto{ skad,0 , 0 , 0 ,p};
					dodajdopol(p->plewy->pkorzenpol, dokad, droga);
					p = nullptr; 
				}
			}
			else if (skad > p->nazwa)  // w prawo
			{
				if (p->pprawy) // jezeli mozna isc w prawo
					p = p->pprawy;
				else
				{
					p->pprawy = new miasto{ skad,0 , 0 , 0 ,p };
					dodajdopol(p->pprawy->pkorzenpol, dokad, droga);
					p = nullptr; 
				}
			}
			else if (skad == p->nazwa)//miasto jest juz dodane
			 {
				 dodajdopol(p->pkorzenpol, dokad, droga);//dodaj samo polaczenie
				 return;
			 }
			
		}
	}

}

void dodajdopol(polaczenia *& pkorzen, const int dokad, const double droga)
{
	if (not pkorzen)//drzewo polaczen jest puste
		pkorzen = new polaczenia{ dokad,droga , 0, 0, 0 };

	else // w drzewie polaczen juz cos jest 
	{
		auto p = pkorzen;

		while (p)
		{
			
			if (droga< p->droga) // idziemy w lewo
			{
				if (p->plewy)  // jezeli istnieje pLewy
					p = p->plewy;
				else
				{
					p->plewy = new polaczenia{ dokad,droga , 0, 0 ,p };
					p = nullptr; 
				}
			}
			else  // idziemy w prawo
			{
				if (p->pprawy)
					p = p->pprawy;
				else
				{
					p->pprawy = new polaczenia{ dokad,droga , 0, 0 ,p };
					p = nullptr; 
				}
			}
		}
	}
}

void wypiszpol(polaczenia * proot, int wciecie)
{
	const int MNOZNIK = 4;
	if (proot)  // jezeli drzewo jest niepuste
	{
		wypiszpol(proot->plewy, wciecie + 1);
		std::cout << std::setw(wciecie * MNOZNIK) << proot->nazwa <<"-"<<proot->droga<< std::endl;
		wypiszpol(proot->pprawy, wciecie + 1);
	}
}

void wypiszmiasta(miasto *proot, int wciecie)
{
	const int MNOZNIK = 4;
	if (proot != nullptr)  // jezeli drzewo jest niepuste
	{
		wypiszmiasta(proot->plewy, wciecie + 1);
		std::cout << std::setw(wciecie * MNOZNIK) << proot->nazwa<< std::endl;
		wypiszmiasta(proot->pprawy, wciecie + 1);
	}
}

void wczytaj(miasto *& prootm, const std::string & nazwa)
{
	std::ifstream plik;
	plik.open(nazwa);
	if (plik.good()==false)
	{
		std::cout << "Pliku nie znaleziono" << std::endl;
		return;
	}
	std::string linia;

	int licz = 0;
	int skad = 0;
	int dokad = 0;
	int droga = 0;
	std::string del = "()->,:";
	while (std::getline(plik, linia))
	{
		for (int i =0; i<del.length();i++)
		{
			size_t pos = linia.find(del[i]);
			if (pos != std::string::npos)
				linia.replace(linia.begin() + pos, linia.begin() + pos + 1, " " );	
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
						licz=0;
						dodajdomiast(prootm, skad, dokad, droga);
						break;
					}
				
				}
			}
		}
	}

	plik.close();
}

void wpisz(const std::string & output, const double droga, std::string & kolejnosc)

{
	std::ofstream plik;
	plik.open(output);
	plik << "Droga: " << droga << std::endl;
	plik << "Kolejnosc odwiedziania miast: ";
	for (int i = 0; i < kolejnosc.length(); i++)
	{
		plik << kolejnosc[i];
	}
	
	plik << std::endl;
	plik.close();
}

miasto * znajdz(miasto *prootm, const int wartosc)
{
	if (not prootm or prootm->nazwa == wartosc)//sprawdzanie czy start to nie nullptr w main!
		return prootm;
	else
	{
		auto p = prootm;

		while (p)
		{
			if (wartosc == p->nazwa)
				return p;
			if (wartosc < p->nazwa)
				p = p->plewy;
			else
				p = p->pprawy;
		}
		// nie ma
		return nullptr;
	}
}

void usunMinPol(polaczenia *& prootpol)
{
	if (prootpol == nullptr)
		return;
	if (prootpol->pprawy == nullptr && prootpol->plewy == nullptr) // jeden elemnet
	{
		delete prootpol;
		prootpol = nullptr;
		return;
	}
	
	if (prootpol->plewy == nullptr && prootpol->pprawy != nullptr)//tylko prawo
	{
		auto temp = prootpol->pprawy;
		delete prootpol;
		prootpol = temp;
		//prootpol->rodzic = nullptr;
		return;
	}
	if (prootpol->plewy != nullptr && prootpol->pprawy == nullptr)//tylko lewo
	{
		delete prootpol->plewy;
		prootpol->plewy = nullptr;
		//prootpol->plewy->rodzic = nullptr;
		return;
	}
	auto p = prootpol;
	while (p)
	{
		if (p->plewy)
			p = p->plewy;
	}

	if (p->pprawy) //minimalna wartosc posiada prawego potomka
	{
		auto temp = p->pprawy;
		auto rodz = p->rodzic;
		delete p;
		rodz->plewy = temp;
		temp->rodzic = rodz;
		p = nullptr;
		return;
	}
	else // nie posiada potomkow
	{
		auto temp = p->rodzic->plewy;
		temp = nullptr;
		delete p;
		p = nullptr;
		return;
	}

}

miasto *minimum(polaczenia *prootpol, miasto * prootm, int & suma)
{
	if (prootpol == nullptr)
		return nullptr; 

	if (prootpol->plewy == nullptr)
	{
		miasto * najblizej = znajdz(prootm, prootpol->nazwa);
		if(najblizej!=nullptr) 
			suma += prootpol->droga;
		return najblizej;
	}

	while (prootpol->plewy)
		prootpol = prootpol->plewy;
	
	miasto * najblizej = znajdz(prootm, prootpol->nazwa);
	if (najblizej != nullptr) 
		suma += prootpol->droga;
	return najblizej;
}

void algorytm(miasto * prootm, miasto  *prootw, miasto * start, int & suma, std::string & kolejnosc)
{
	int ostatni = 0;
	int startpkt = start->nazwa;
	auto temp = start;
	auto p = start;
	while (prootm != nullptr)
	{
		temp = p;
		miasto * x = minimum(temp->pkorzenpol, prootm, suma);
		kolejnosc += std::to_string(temp->nazwa);
		kolejnosc += "->";
		//std::cout << kolejnosc << std::endl;
		if (x == nullptr || x->nazwa == startpkt )
		{	
			ostatni = minimalnepol(temp->pkorzenpol);
				usunMinPol(temp->pkorzenpol);
				x = minimum(temp->pkorzenpol, prootm, suma);
				
		}		
			przenies(prootm, temp->nazwa, prootw);
			p = x;
		
	}
	suma += ostatni;
	kolejnosc += std::to_string(startpkt);
}

miasto * minimalnemiasto(miasto*prootm)
{
	if (not prootm)
		return nullptr;

	if (prootm->plewy)
		return minimalnemiasto(prootm->plewy);
	return prootm;
}

miasto * nastepny(miasto *prootm, miasto * element)
{
	if (not prootm || not element)
		return nullptr;
	if (element->pprawy) // przeskocz na prawy i do oporu w lewo
	{
		element = element->pprawy;
		while (element->plewy)
			element = element->plewy;
		return element;
	}
	while (element->rodzic) //idz do gory az nie element nie bedzie lewym potomkiem
	{
		if (element->rodzic->plewy == element)
			return element->rodzic;
		element = element->rodzic;
	}
	return nullptr; //brak potomka
}

void usun(miasto *& prootm, const int numer)//ufikusnij
{
	if (prootm == nullptr) return ;

	if (prootm->nazwa == numer)
	{
		if (prootm->pprawy == nullptr && prootm->plewy == nullptr)//pojedynczy element w drzewie
		{
			delete prootm;
			prootm = nullptr;
			return;
		}

		if (prootm->pprawy != nullptr && prootm->plewy == nullptr) //posiada prawy, lewego nie
		{
			auto temp = prootm->pprawy;
			delete prootm;
			prootm = temp;
			return;
		}

		if (prootm->pprawy == nullptr && prootm->plewy != nullptr) //posiada lewy, prawego nie
		{
			auto temp = prootm->plewy;
			delete prootm;
			prootm = temp;
			return;
		}
	}
	auto dana = znajdz(prootm, numer);

		if (dana->plewy == nullptr && dana->pprawy == nullptr)//Brak potomka
		{
			if (dana->rodzic->pprawy == dana)//prawy potomek
			{
				auto x = dana->rodzic;
				delete dana;
				x ->pprawy =  nullptr;
				dana = nullptr;
				return;
			}
			else //lewy potomek
			{
				auto x = dana->rodzic;
				delete dana;
				x->plewy = nullptr;
				dana = nullptr;
				return;
			}
		}

		if (dana->plewy == nullptr && dana->pprawy != nullptr) //lewy jest null ,prawy nie 
		{		
			if (dana->rodzic->pprawy == dana)//prawy potomek
			{
				auto x = dana->rodzic;
				auto temp = dana->pprawy;
				delete dana;
				x->pprawy = temp;
				temp->rodzic = x;
				dana = nullptr;
				return;
			}
			else //lewy potomek
			{
				auto x = dana->rodzic;
				auto temp = dana->pprawy;
				delete dana;
				x->plewy = temp;
				temp->rodzic = x;
				dana = nullptr;
				return;
			}
		}

		if(dana->pprawy == nullptr && dana->plewy != nullptr)//prawy jest null, lewy nie
		{
			if (dana->rodzic->pprawy == dana)//prawy potomek
			{
				auto x = dana->rodzic;
				auto temp = dana->plewy;
				delete dana;
				x->pprawy = temp;
				temp->rodzic = x;
				dana = nullptr;
				return;
			}
			else //lewy potomek
			{
				auto x = dana->rodzic;
				auto temp = dana->plewy;
				delete dana;
				x->plewy = temp;
				temp->rodzic = x;
				dana = nullptr;
				return;
			}
		}

		if(dana->plewy != nullptr && dana->pprawy != nullptr) // 2 potomki slabo 
		{
				auto min = nastepny(prootm, dana);
				const int temp = min->nazwa;
				auto pol = min->pkorzenpol;
				
				usun(prootm, temp);
				dana->nazwa = temp;
				dana->pkorzenpol = pol;
		}
	}

bool przenies(miasto*&prootm, const int dous, miasto*&prootres)
{
	if (prootm == nullptr ) //puste
		return false;
	 miasto *temp = znajdz(prootm, dous);
	 if (temp == nullptr) return false;
	 dodajdomiastwynik(prootres, temp->nazwa, temp->pkorzenpol); // dodaj do drugiej listy
	 usun(prootm, dous); //usun z 1 lity
	 return true;
}
		
int minimalnepol(polaczenia *prootw)
{
	if (prootw == nullptr)
		return 0;
	if (prootw->plewy == nullptr)
		return prootw->droga;
	while (prootw->plewy)
		prootw = prootw->plewy;
	return prootw->droga;
}
	