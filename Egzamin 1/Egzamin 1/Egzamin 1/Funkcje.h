#pragma once
#ifndef Funkcje_hpp
#define Funckje_hpp


const int W = 7;
const int K = 5;

bool hetman (const std::string& nazwa);

void wczytaj (const std::string& nazwa, int tab [W][K]);

void zapisz(int tab[W][K], const std::string& wyjscie);

void przeksztalc(const std::string& wejscie, const std::string& wyjscie);

#endif