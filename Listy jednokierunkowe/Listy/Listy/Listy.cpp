#include "pch.h"
#include <iostream>
#include "Funkcje.h"

int main()
{
	element * phead = nullptr;

	for (int i : { 13,14,2,4,4,6,7,8,8,8,11,15 })
	{
		//dodajnaPocz(phead, i);
		dodajnaKon(phead, i);
	}
	wypisz(phead);

	//dodajIT(phead, 10);

	//usunE(phead, 5);

	//usunElementy(phead, 2);

	//odwroc(phead);

	//powtorzenia(phead);

	element *phead1 = nullptr;
	element *phead2 = nullptr;
	for (int i : {1,1,2,3})
	{
		dodajnaKon(phead1, i);
	}
	for (int i : {1,4,5,6,7,8,9})
	{
		dodajnaKon(phead2, i);
	}

	/*element *phmno = sumaMno(phead1, phead2);
	wypisz(phmno);*/

   /* element *philo = iloMno(phead1, phead2);
	wypisz(philo);*/

	//element *phroz = rozMno(phead1, phead2);//(phead1\phead2)
	//wypisz(phroz);

	/*unost(phead2);
	wypisz(phead2);*/

	/*usunparz(phead);
	wypisz(phead);*/

	/*element * scalone = scal(phead1, phead2);
	wypisz(scalone);*/

	/*sortuj(phead);
	wypisz(phead);*/

	//std::pair<typ, typ> ekstrema = exmin(phead3);
	//std::cout <<"minimum: "<< ekstrema.first << std::endl;
	//std::cout << "maximum: " << ekstrema.second << std::endl;

	/*element *szukany = znajdzIT(phead, 6);
	if(szukany!=nullptr)
		wypisz(listatodele(phead, szukany));*/

	//wypisz(listaodwart(phead, 15));

	//przesun(phead);

	/*usunliste(phead);
	if (phead == nullptr) std::cout << "Lista pusta" << std::endl;
	else wypisz(phead);*/
}
