// igor.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
int suma1(int n, int r, int a, int &sumawzor)
{
	sumawzor = (n*(2 * a + (n - 1)*r)) / 2;
	return sumawzor;
}
int suma2(int n, int r, int a,int &sumamoje)
{
	sumamoje = n * (a + r) - r;
	return sumamoje;
}
int main()
{
	const int n = 200;
	const int r = 3;
	const int a = 4;
	int sumawzor=0;
	int sumamoje = 0;
	suma1(n, r, a, sumawzor);
	suma2(n, r, a, sumamoje);
	std::cout << sumawzor << std::endl;
	std::cout << sumamoje << std::endl;
	return 0;
}