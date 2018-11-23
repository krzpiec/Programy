#pragma once
#ifndef Funkcje_h
#define Funkcje_h

void zapisz(std::ostream& s);

double srednia(std::istream & wejscie);

double frobenius(std::istream& s, double & frob);

void uniq(std::istream& s, std::ostream& out);

void srednia_w(std::istream& s, std::ostream& out);

void wypisz(std::istream& s, std::ostream& out);

void transponuj(std::istream& in, std::ostream& out);

void pierwsze(std::istream& in, std::ostream& out);

std::vector<std::string> rozdziel(const std::string& tekst);

#endif

