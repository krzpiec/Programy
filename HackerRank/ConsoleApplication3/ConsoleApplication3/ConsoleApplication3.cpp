// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// Czas : 45min 32s łacznie z testami i komentarzem

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
	vector<int> arr = { 2,2,3,4,5 };
	int d = 1;
	int beauty = 0;
	int i = 0;

	while (i < arr.size() - 1)
	{
		int liczba = 0;
		int trip = 0;
		liczba = arr[i];
		for (int j = i+1; j < arr.size(); j++)
		{
			if (arr[j] == liczba +d )
			{
				liczba = arr[j];
				trip++;
				if (trip == 3)
				{
					beauty++;
					break;
				}
			}
		}
	}
	cout << beauty;
	}
