#include "Funkcje.h"
#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <cmath>

constexpr double PI = 3.14159265;

struct pkt
{
	double x;
	double y;
	double z;
};

struct indeks
{
	int i;
	int j;
	int k;
};

std::vector<pkt> losuj(const int N, const int min, const int max) //Losuje N punktow pseudoloswych typu <int>
{
	std::vector<pkt> myvec(N);

	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> number(min, max);

	for (int i = 0; i < N; i++)
	{
		myvec[i].x = number(silnik);
		myvec[i].y = number(silnik);
		myvec[i].z = number(silnik);
	}
	/*
	myvec[0].x = myvec[1].x;
	myvec[0].y = myvec[1].y;
	myvec[0].z = myvec[1].z;
	petla ponizej wyklucza sytuacje w ktorej 2 pkt maja takie same wspolrzedne.
	*/
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			if ((myvec[i].x == myvec[j].x) && (myvec[i].y == myvec[j].y) && (myvec[i].z == myvec[j].z));
			{
				while (myvec[i].x == myvec[j].x)
				{
					myvec[i].x = number(silnik);
				}
				while (myvec[i].y == myvec[j].y)
				{
					myvec[i].y = number(silnik);
				}
				while (myvec[i].z == myvec[j].z)
				{
					myvec[i].z = number(silnik);
				}
			}
		}
	}

	return myvec;
}

double odl(const pkt& a, const pkt& b) //liczy odleglosc miedzy dwoma pkt
{
	int odleglosc = 0;
	odleglosc = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));

	return odleglosc;
}

std::pair<pkt, pkt> para_odl(const std::vector<pkt>& myvec) // zwraca pare najbardziej odleglych pkt 
{
	std::pair<pkt, pkt> para;
	double najwieksza = 0;
	for (int i = 0; i < myvec.size(); i++)
	{
		for (int j = i + 1; j < myvec.size(); j++)
		{
			if (odl(myvec[i], myvec[j]) > najwieksza)
			{
				para.first = myvec[i];
				para.second = myvec[j];
			}
		}

	}
	return para;
}

std::vector<double> sortuj(std::vector<double>& myvec) // sortuje wektor od najmniejszej do najwiekszej wartosci
{
	for (int i = 0; i < myvec.size() - 1; i++)
	{
		for (int j = 0; j < myvec.size() - 1; j++)
		{
			if (myvec[j] > myvec[j + 1])
			{
				std::swap(myvec[j], myvec[j + 1]);
			}
		}
	}
	return myvec;
}

bool wspolliniowe(const pkt& a, const pkt& b, const pkt & c) //Czy podane pkt sa wspolliniowe
{
	std::vector<double> odleg = { odl(a,b), odl(a,c), odl(b,c) };
	sortuj(odleg);
	if (odleg[2] == (odleg[1] + odleg[0]))
	{
		return true;
	}
	else
	return false;
}

double pole(double x, double y, double z)
{
	double p = (x + y + z) / 2;
	 double p1 = p - x;
	 double p2 = p - y;
	 double p3 = p - z;
	 double pole = p * (p - x)*(p - y)*(p - z);
	return pole;
}

void wypisz(std::ostream& strumien, const std::vector<pkt>& chmura) // przekazuje punkty do cout
{
	for (int i = 0; i < chmura.size(); i++)
	{
		strumien << chmura[i].x;
		strumien << " ";
		strumien << chmura[i].y;
		strumien << " ";
		strumien << chmura[i].z;
		strumien << std::endl;
	}
}

double najmpole(const std::vector<pkt>& chmura, std::vector<indeks>& indeks, const int min, const int max)//wyznacza najmniejsze pole trojkata 
{
	std::vector<double> odleglosci(3);
	pkt a = { 0,0,0 };
	pkt b = { max, max, max };
	long double odlmax = odl(a,b);
	long double polemax = pole(odlmax, odlmax, odlmax);
	long double porownaj = 0;
	for (int i = 0; i < chmura.size(); i++)
	{
		for (int j = i + 1; j < chmura.size(); j++)
		{
			for (int k = j + 1; k < chmura.size(); k++)
			{

				if ((wspolliniowe(chmura[i], chmura[j], chmura[k]) == false))
				{
					porownaj = pole( odl(chmura[i], chmura[j]), odl(chmura[j], chmura[k]), odl(chmura[k], chmura[i]));
					if ((porownaj < polemax)&&(porownaj>0))
					{

						odleglosci[0] = odl(chmura[i], chmura[j]);
						odleglosci[1] = odl(chmura[j], chmura[k]);
						odleglosci[2] = odl(chmura[k], chmura[i]);

						indeks[0].i = i;
						indeks[0].j = j;
						indeks[0].k = k;
					}
				}

			}
		}
	}
	
	sortuj(odleglosci);
	/*
	std::cout << odleglosci[0] << std::endl;
	std::cout << odleglosci[1] << std::endl;
	std::cout << odleglosci[2] << std::endl;
	*/
	
	long double result = pole(odleglosci[0], odleglosci[1], odleglosci[2]);
	if (result != 0)
	{
		return result;
	}
	else
	{
		std::cerr << " Blad";
		return 0;
	}
	
}

double kacik(const pkt&a, const pkt& b, const pkt & c)
{
	std::vector<double> odleg = { odl(a,b), odl(a,c), odl(b,c) };
	sortuj(odleg);
	double i = odleg[0];
	double j = odleg[1];
	double k = odleg[2];
	double cosinus = ((pow(i, 2) + pow(j, 2) - pow(k, 2)) / (2 * i*j));
	double result = (acos(cosinus) * 180) / PI;
	if (isnan(result) == 1)
	{
		std::cerr << "Blad";
		return 0;
	}
	else
		return result;

}

double plaszczyzna(std::vector<pkt>& chmura)
{
	pkt x = chmura[0];
	pkt y = chmura[1];
	pkt z = chmura[2];
	int indeks = 3;
	pkt t = chmura[indeks];
	while ((wspolliniowe(x, y, t) == true) || (wspolliniowe(x, z, t) == true) || (wspolliniowe(z, y, t) == true))
	{
		indeks++;
	}
	double a = ((x.y - x.y)*(z.z - x.z));
	double a1 = ((y.z - x.z)*(z.y - x.y));
	double b = ((y.z - x.z)*(z.x - x.x));
	double b1 = ((y.x - x.x)*(z.z - x.z));
	double c = ((y.x - x.x)*(z.y - x.y));
	double c1 = ((y.y - x.y)*(z.x - x.x));
	double r = (-1)*(x.x*(a - a1) + x.y*(b - b1) + x.z*(c - c1));
	double licznik = t.x*(a - a1) + t.y*(b - b1) + t.z*(c - c1) - r;
	if (licznik < 0)
	{
		licznik = licznik * (-1);
	}
	double mianownik = sqrt(pow(a - a1, 2) + pow(b - b1, 2) + pow(c - c1, 2));
	return licznik / mianownik;
}