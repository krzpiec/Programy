#include "pch.h"
#include <iostream>
//105
void zad1(std::ostream& s, const int W, const int K)
{
	int petla = floor(W / 2);
	for (int i = 0; i < petla; i++)
	{
		for (int j = 0; j < K; j++)
		{
			s << "X ";
		}
		s << std::endl;
		for (int k = 0; k < K; k++)
		{
			s << ". ";
		}
		s << std::endl;
	}
	if (W % 2 == 1)
	{
		for (int i = 0; i < K; i++)
		{
			s << "X ";
		}
	}

}

void zad2(std::ostream& s, const int W, const int K)
{
	for (int j = 0; j < W; j++)
	{
		for (int i = 0; i < K; i++)
		{
			if (i % 2 == 0)
			{
				s << "X";
			}
			if(i%2 == 1)
			{
				s << ".";
			}
		
		}
		s << std::endl;
	}
}

void zad3(std::ostream& s, const int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			s << ".";
		}
		for (int k = i; k < N; k++)
		{
			s << "X";
		}
		s << std::endl;
	}
}

void zad4(std::ostream& s, const int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N ; j++)
		{
			s << ".";
		}
		for (int k = 0; k < i+1; k++)
		{
			s << "X";
		}
		s << std::endl;
	}
}
int main()

