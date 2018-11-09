#include "Funkcje.h"
#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>



std::vector<int> fill(std::vector<int>& myvec, const int N, const int min, const int max)
{
	std::default_random_engine silnik;
	silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> numbers(min, max);

	for (int i = 0; i < N; i++)
	{
		myvec.push_back(numbers(silnik));
		for (int j = 0; j < i; j++)
		{

			if (myvec[j] == myvec[i])
			{
				myvec[i] = numbers(silnik);
				j = -1;
			}
		}
	}
	return myvec;
}
std::vector<int> merge(const std::vector<int>& myvec, const std::vector<int>& myvec1, std::vector<int>& result)
{
	for (int i = 0; i < myvec.size(); i++)
	{
		result.push_back(myvec[i]);
	}
	for (int i = 0; i < myvec1.size(); i++)
	{
		result.push_back(myvec1[i]);
	}
	return result;
}
std::vector<int> usunpowt(std::vector<int>& myvec)
{
	std::vector<int> indeks;
	for (int i = 0; i < myvec.size() - 1; i++)
	{
		if (myvec[i] == myvec[i + 1])
		{
			indeks.push_back(i);
		}
	}
	for (int i = 0; i < indeks.size(); i++) //usuniecie powtorzen z result
	{
		myvec.erase(myvec.begin() + (indeks[i] - i));
	}
	myvec.shrink_to_fit();
	return myvec;
}

std::vector<int> sort(std::vector<int>& myvec)
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

std::vector<int> prime(const std::vector<int>& myvec, std::vector<int>& prime)
{
	for (int i = 0; i < myvec.size(); i++)
	{
		if (myvec[i] == 2)
		{
			prime.push_back(myvec[i]);
		}
		if ((myvec[i] != 0) && (myvec[i] != 1) && (myvec[i] != 2))
		{
			int podzielnosc = 0;
			for (int j = 2; j < myvec[i]; j++)
			{
				if (myvec[i] % j == 0)
				{
					podzielnosc = 1;
				}
			}
			if (podzielnosc == 0)
			{
				prime.push_back(myvec[i]);
			}
		}

	}
	return prime;
}

void reverse(std::vector<int>& myvec)
{

	for (int i = 0; i < myvec.size() / 2; i++)
	{
		std::swap(myvec[i], myvec[myvec.size() - 1 - i]);
	}
}

void print(const std::vector<int>& myvec, const int N)
{
	for (int i = 0; i < myvec.size(); i++)
	{
		std::cout << std::setw(N) << std::fixed << myvec[i];
	}
	std::cout << std::endl;
}

std::vector<int> repetition(std::vector<int>& myvec, std::vector<int>& myvec1, std::vector<int>& result)
{
	std::vector<int> indeks;
	for (int i = 0; i < myvec.size(); i++)
	{
		int liczba = myvec[i];
		for (int a = 0; a < myvec1.size(); a++)
		{
			if (myvec1[a] == liczba)
			{
				indeks.push_back(i);
			}
		}

	}
	for (int i = 0; i < myvec.size(); i++) //kopia myvec do result
	{
		result.push_back(myvec[i]);
	}
	for (int i = 0; i < indeks.size(); i++) //usuniecie powtorzen z result
	{
		result.erase(result.begin() + (indeks[i] - i));
	}
	result.shrink_to_fit();
	return result;
}

int liczba(std::vector<int> myvec, int& liczba)
{
	liczba = myvec[0];
	for (int i = 1; i < myvec.size(); i++)
	{
		liczba = liczba * myvec[i];
	}
	return liczba;
}

std::vector<int> generate(std::vector<int>& ciag, const int N)
{

	for (int i = 2; i < N; i++) //generuje wektor kolejnych liczb pierwszych 
	{
		if (N % i == 0)
		{
			ciag.push_back(i);
		}
	}

	return ciag;
}