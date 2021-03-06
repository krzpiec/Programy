#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <chrono>
struct punkt
{
	double x;
	double y;
	double z;
};
double odleglosc(const punkt& a, const punkt& b)
{
	double odl = 0;
	odl = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
	return odl;
}
std::vector<punkt> losuj_punkt(const int N)
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::normal_distribution<double> rozklad(0, 5);

	std::vector<punkt> pkt(N);

	for (int i = 0; i < N; i++) {

		pkt[i].x = rozklad(silnik);
		pkt[i].y = rozklad(silnik);
		pkt[i].z = rozklad(silnik);
	}
	return pkt;
}

std::pair<punkt, punkt> znajdz(const std::vector<punkt>& chmura)
{
	double najw = 0;
	std::pair<punkt, punkt> para;
	for (int p = 0; p < chmura.size(); p++)
	{

		for (int d = p + 1; d < chmura.size(); d++)
		{

			if (odleglosc(chmura[p], chmura[d]) > najw)
			{
				najw = odleglosc(chmura[p], chmura[d]);
				para.first = chmura[p];
				para.second = chmura[d];
			}

		}

	}

	return para;
}


int main()
{

	punkt a{ 1,2,3 };
	punkt b{ 3,2,1 };
	int N = 3;
	std::cout << odleglosc(a, b);
	auto chmura = losuj_punkt(3);
	auto para = znajdz(chmura);
	return 0;
}