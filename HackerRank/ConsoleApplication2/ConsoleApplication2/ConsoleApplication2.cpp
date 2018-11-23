// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;
const int W = 5;
const int K = 4;

void zad4 (std::ostream& s, int tab[][K], const int W, const int K)
{
	int x = 0;
	int y = 0;
	int iterator = 1;
	while (y < K)
	{
		if (y % 2 == 0)
		{
			x = 0;
			while (x < W)
			{
				tab[x][y] = iterator;
				iterator++;
				x++;
			}
			y++;
		}
		else
		{
			x = W - 1;
			while (x >= 0)
			{
				tab[x][y] = iterator;
				iterator++;
				x--;
			}
			y++;
		}
	}

	for (int i = 0; i < W; i++)

	{
		for (int j = 0; j < K; j++)
		{
			s << std::setw(4) << tab[i][j];
		}
		s<< std::endl;
	}
}

void zad4odw(std::ostream& s, int tab[][K], const int W, const int K)
{
	int x = 0;
	int y = 0;
	int iterator = 1;
	while (x < W)
	{
		if (x % 2 == 0)
		{
			y = 0;
			while (y < K)
			{
				tab[x][y] = iterator;
				iterator++;
				y++;
			}
			x++;
		}
		else
		{
			y = K - 1;
			while (y >=0)
			{
				tab[x][y] = iterator;
				iterator++;
				y--;
			}
			x++;
		}
	}

	for (int i = 0; i < W; i++)

	{
		for (int j = 0; j < K; j++)
		{
			s << std::setw(4) << tab[i][j];
		}
		s << std::endl;
	}
}

int main()
{

	//int tab[W][K] = { 0 };
	//zad4odw(std::cout, tab, W, K);
	//zad4(std::cout, tab, W, K);
	vector<int> s = { 1,2,2,3 };
	int powt=1;
	int result = 0;
	std::sort(s.begin(), s.end());
	for (int i = 0; i < s.size()-1; i++)
	{
		if (s[i] == s[i + 1]) powt++;
		if (powt > result) result = powt;
		if (s[i] != s[i + 1]) powt = 1;
	}
	cout << result;
}
