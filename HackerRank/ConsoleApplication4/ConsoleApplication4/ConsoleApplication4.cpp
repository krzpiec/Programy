// ConsoleApplication4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	string linia = "1 2 3 4 5";
	stringstream ss (linia);

	vector<int> tab;
	int liczba = 0;
	while (ss >> liczba)
	{
		tab.push_back(liczba);
	}
	int rot = 4;
	for (int j = 0; j < rot; j++)
	{
		for (int i = 0; i < tab.size() - 1; i++)
		{
			swap(tab[i], tab[i + 1]);
		}
	}
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i];
	}
	
}