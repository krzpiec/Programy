#pragma once
#ifndef  Funkcje_h
#define  Funkcje_h

typedef int typ;

struct element
{
	int wartosc;
	element* pnext;
};

void usunliste(element *& phead);

std::pair<typ, typ> exmin(element * phead);

void dodajnaKon(element *& phead, const typ wart);

void dodajnaPocz(element *& phead, const typ wart);

void wypelnij(element *& pglowa, const typ wart);

void wypisz(element *phead);

void dodajIT(element *& phead, typ liczb);

element *znajdzIT(element *& phead, typ liczba);

void usunE(element *& phead, const typ wart);

void usunElementy(element *& phead, const typ liczba);

void odwroc(element *& phead);

void powtorzenia(element *& phead);

element *iloMno(element * ph1, element * ph2);

element *sumaMno(element * ph1, element * ph2);

element *rozMno(element * ph1, element * ph2);

void usunparz(element *& phead);

void usunost(element *& phead);

element *scal(element * ph1, element * ph2);

void sortuj(element *& phead);

element *listatodele(element *phead, element *&ten);

element *listaodwart(element *phead, const typ wart);

void przesun(element*&phead);

#endif