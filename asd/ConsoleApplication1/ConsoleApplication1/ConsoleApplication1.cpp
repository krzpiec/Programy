// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;
	//std::cout << vec.size();
	for (int i = 0; i < 8; i++)
	{
		vec.push_back(i);
		std::cout << vec[i];
	}
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] ++;
		std::cout << vec[i];
	}
}