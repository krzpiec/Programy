#pragma once
#ifndef FUNKCJE_H
#define FUNKCJE_H

typedef int typ;

struct element
{
	typ wartosc;
	element *pnext;
	element *pprev;
};

void wypelnij(std::vector<int>& liczby, const int n);

void dodajnaPocz(element * & phead, element * & ptail, const typ wart);

void wypiszodpocz(element *  phead);

void wypiszodkon(element *  ptail);

void dodajnaKon(element * & phead, element * & ptail, const typ wart);

void dodajdopos(element * & phead, element * & ptail, const typ wart);

void odwroc(element * & phead, element * & ptail);

element *znajdz(element *phead, const typ wart); 

void usunE(element *& phead, const typ wart);

void przenies(element *& pheadwej, element *& pheadwyj, element *& ptailwej, element *& ptailwyj, const typ wart);

void usunliste(element *& phead, element *& ptail);

void sort(element *& phead, element *& ptail);

void ostnapocz(element *& phead, element *& ptail);

#endif // !FUNKCJE_H

