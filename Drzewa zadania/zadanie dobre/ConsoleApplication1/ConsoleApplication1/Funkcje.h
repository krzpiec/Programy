#pragma once
#ifndef Funkcje_h
#define Funkcje_h

typedef int typ;

struct wezel
{
	int data;
	wezel *prawy;
	wezel *lewy;
};

void wypisz(wezel *proot, int wciecie);

void wypelnijrek(wezel * & proot, const typ data);

void wypelnijit(wezel * & proot, const typ data);

void odbij(wezel *proot);

void wypiszwszerz(wezel *proot);

#endif // !Funkcje_h
