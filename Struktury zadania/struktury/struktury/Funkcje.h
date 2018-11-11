#pragma once
#ifndef Funkcje_h
#define Funkcje_h


struct pkt; // struktura dla punktu

struct indeks; // uzyte do przechowania indeksu

std::vector<pkt> losuj(const int N, const int min, const int max); //Losuje N punktow pseudoloswych typu <int>

double odl(const pkt& a, const pkt& b); //liczy odleglosc miedzy dwoma pkt

std::pair<pkt, pkt> para_odl(const std::vector<pkt>& myvec); // zwraca pare najbardziej odleglych pkt 

std::vector<double> sortuj(std::vector<double>& myvec); // sortuje wektor od najmniejszej do najwiekszej wartosci

bool wspolliniowe(const pkt& a, const pkt& b, const pkt & c); //Czy podane pkt sa wspolliniowe

double pole(const double x, const double y, const double z); //wyznacza pole dla danych bokow trojakta

void wypisz(std::ostream& strumien, const std::vector<pkt>& chmura); // przekazuje punkty do strumienia wyjscia cout

double najmpole(const std::vector<pkt>& chmura, std::vector<indeks>& indeks, const int min, const int max);//wyznacza najmniejsze pole trojkata

double kacik(const pkt&a, const pkt& b, const pkt & c); // wyznacza kat miedzy dwoma krotszymi bokami trojakta

double plaszczyzna(std::vector<pkt>& chmura );// odleglosc pkt t od plaszyczny pi: (x,y,z)

#endif