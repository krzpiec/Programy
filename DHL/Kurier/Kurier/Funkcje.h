#pragma once
#ifndef Funkcje_H
#define Funkcje_H

struct polaczenia
{
	int nazwa;
	double droga;
	polaczenia * plewy;
	polaczenia * pprawy;
	polaczenia * rodzic;

};

struct miasto
{
	int nazwa;
	polaczenia * pkorzenpol;
	miasto *plewy;
	miasto *pprawy;
	miasto *rodzic;
};

void usundrzewomiast(miasto *prootm);
//Funkcja usuwa drzewo miast;

void dodajdomiastwynik(miasto *& prootw, const int nazwa, polaczenia *& polacz);
//Funkcja dodaje do drugiej listy miast

void dodajdomiast(miasto *& prootm, const int skad, const int dokad, const double droga);
//Funkcja do drzew miast dodaje kolejne miasto, badz jezeli juz istnieje doda samo polaczenie;

void dodajdopol(polaczenia *& pkorzen, const int dokad, const double droga);
//Funckja do drzewa polaczen dodaje kolejne (uzyte w dodajdomiast);

void usunMinPol(polaczenia *& prootpol);
//Funkcja usuwa minimalne polaczenie;

void wypiszpol(polaczenia * proot, int wciecie);
//Funckja wypisuje drzewo polaczen danego miasta (testy)

void wypiszmiasta(miasto *proot, int wciecie);
//Funkcja wypisuje drzewo miast (testy)

void wczytaj(miasto *& prootm, const std::string & nazwa);
//Funkcja wczytuje dane z pliku wejscowego do drzewa; POPRAWIC!!!!!

void wpisz(const std::string & output, const double droga, std::string & kolejnosc);
//Funckja wpisuje drogie i kolejnosc miast do pliku wyjsciowego !!!Wczytam ze string, z drzewa nie jestem w stanie odczytac kolejnosci wstawiania, a robienie listy mija sie z celem;

miasto * znajdz(miasto *proot, const int wartosc);
//Funkcja znajduje miasto o zadanym numerze -> uzyte do pkt startowego

miasto *minimum(polaczenia *prootpol, miasto * prootm, int & suma);
// Funkcja znajduje najblizsze miasto;

void algorytm(miasto* prootm,miasto*prootw, miasto * start, int & suma, std::string & kolejnosc);
//testuje algor

bool przenies(miasto*&prootm, const int dous, miasto*&prootres);
//Funckaj przenosi wezel do innego drzewa, true - znaleziono i przeniesiono, false jezeli nie ma tego elementu(zeby 2xznajdz nie wywolywac)

miasto* minimalnemiasto(miasto*prootm);
//Funkcja uzyta do znajlezienia nastepnika miasta, znajduje minimalny element danego segmentu

miasto * nastepny(miasto *prootm, miasto * znajdz);
//Funckja uzyta w  przenoszeniu, znajduje nastepnik danego elementu

void usun(miasto *& prootm, const int numer);
//Funkcja usuwajaca dany wezel

int minimalnepol(polaczenia *prootw);
//Funkcja znajduje minimalne polaczenie

#endif