#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include "Funckje.h"
#include <sstream> 


void zapisz(std::ostream& s)
{
	//const int SZEROKOSC = 10;
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());

	std::uniform_int_distribution<int> liczby(1, 9);
	std::uniform_int_distribution<int> kolumny(5, 10);
	std::uniform_int_distribution<int> wiersze(5, 10);
	int lwier = wiersze(silnik);
	for (int i = 0; i < lwier; i++)
	{
		int lkol = kolumny(silnik);
		for (int j = 0; j < lkol; j++)
		{
			s << std::setw(2) << std::fixed << liczby(silnik);
		}
		s << std::endl;
	}
}

double srednia(std::istream & wejscie)
{
	int licznik = 0;
	double suma = 0;
	double licz = 0;
	while (wejscie)
	{
		wejscie >> licz;
		if (!wejscie) break;
		suma += licz;
		licznik++;

	}
	return suma / licznik;
}

double frobenius(std::istream& s, double & frob)
{
	double licz = 0;
	while (s)
	{
		s >> licz;
		if (!s) break;
		frob += pow(licz, 2);

	}
	return frob;
}

void uniq(std::istream& s, std::ostream& out)
{	
	std::vector<int> liczby;
	std::vector<int> indeks;
	std::string linia;
	while (getline(s, linia))
	{
		for (int i = 0; i < linia.length(); i++)
		{
			if (isdigit(linia[i]))
			{
				liczby.push_back(linia[i] - '0');
			}
		}
		indeks.push_back(liczby.size()+1);//pozycja endl;

		for (int i = 0; i < liczby.size() - 1; i++)
		{
			if (liczby[i] == liczby[i + 1])
			{
				liczby.erase(liczby.begin() + i, liczby.begin() + i + 1);
			}
		}
		for (int j = 0; j < liczby.size(); j++)
		{
			out << std::setw(2) << std::fixed << liczby[j];
		}
		out << std::endl;
		liczby.clear();
	}
}

void srednia_w(std::istream& s, std::ostream& out)
{
	double suma = 0;
	int ile = 0;
	std::string linia;
	out << "Srednia kazdego z wierszy: | ";
	while (getline(s, linia))
	{
		for (int i = 0; i < linia.length(); i++)
		{
			if (isdigit(linia[i]))
			{
				suma += linia[i];
				ile++;				
			}
		}
		double result = (suma / ile) - '0';
		out << std::setprecision(2)<<result;
		out << " | ";
		suma = 0;
		ile = 0;
	}
	out << std::endl;
}

void wypisz(std::istream& s, std::ostream& wyj)
{
	std::string linia;
	wyj << "Macierz pierwotna: " << std::endl;
	while(getline(s,linia))
	{
		wyj << linia << std::endl;
	}

}

void transponuj(std::istream& in, std::ostream& out)
{
	std::vector<std::vector<int>> myvec;
	std::string linia;
	while (getline(in, linia))
	{
		std::vector<int> temp;
		for (int i = 0; i < linia.length(); i++)
		{
			if (isdigit(linia[i]))
			{
				temp.push_back(linia[i] - '0');
			}
		}
		myvec.push_back(temp);

	}
	int dlugosc = myvec.size(); //rozmiar nowego wektora do transponowania
	for (int i = 0; i < myvec.size(); i++)
	{
		for (int j = 0; j < myvec[i].size(); j++)
		{
			std::cout<<" " << myvec[i][j];
			if (myvec[i].size() > dlugosc)
			{
				dlugosc = myvec[i].size();
			}
		}
		std::cout << std::endl;
	}
	
	/////////////////////////wypelniony wektor 1 + dlugosc wektora 2
	std::vector<std::vector<int>> vec;
	for (int i = 0; i < dlugosc; i++) ////nie wiem jak nadac dlugosc 2d wektorowi wiec robie tak
	{
		std::vector<int> temp;
		for (int j = 0; j < dlugosc; j++)
		{
			temp.push_back(0);
		}
		vec.push_back(temp);
	}
	std::cout << "Proba" << std::endl;

	for (int i = 0; i < myvec.size(); i++)
	{
		for (int j = 0; j < myvec[i].size(); j++)
		{
			vec[i][j] = myvec[i][j];

		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			//int x = vec[i][j];
			//vec[i][j] = vec[j][i];
			//vec[j][i] = x;
			std::swap(vec[i][j] , vec[j][i]);
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] != 0)
			{
				out << std::setw(2) << vec[i][j];
			}

		}
		out << std::endl;
	}
		out << std::endl;

}

void pierwsze(std::istream& in, std::ostream& out)
{
	std::string linia;
		while (getline(in, linia))
		{
			for (int i = 0; i < linia.length(); i++)
			{
				if (linia[i] == ' ') 
					break;
				out << linia[i];
			}
			out << std::endl;
		}
}

std::vector<std::string> rozdziel(const std::string& tekst)
{	
	std::vector<std::string> result;
	std::string linia;
	for (int i = 0; i < tekst.size(); i++)
	{
		if (tekst[i] == ' ')
		{
			result.push_back(linia);
			linia.clear();
		}
		else linia += tekst[i];
	}
	result.push_back(linia);
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}
	return result;
}

