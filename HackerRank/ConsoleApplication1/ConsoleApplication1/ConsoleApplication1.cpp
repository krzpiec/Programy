// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector >
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	string s = "12:05:45PM";
	string help;
	int po = 0;
	int przed = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'P') po++;
	}
	if (po == 0) przed++;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
		{
			help+=s[i];
		}
	}
	size_t position = s.find(help);
	s.erase(s.begin()+position, s.end());
	
	if (przed == 1)
	{
		string hour;
		int godzina = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ':') break;
			else hour += s[i];
		}
		godzina = stoi(hour);
			if (godzina >= 12) godzina -= 12;
			hour.clear();
			if (godzina < 10)
			{
				hour = '0' +to_string(godzina) ;
				s.replace(s.begin(), s.begin() + 2, hour);
			}
			else
			{
				hour = to_string(godzina);
				s.replace(s.begin(), s.begin() + 2, hour);
			}
			cout << s;
	}
	else
	{
		string hour;
		int godzina = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ':') break;
			else hour += s[i];
		}
		if(stoi(hour)==12) 
		godzina = stoi(hour) + 12;
		if (godzina >= 24) godzina -= 24;
		hour.clear();
		hour = to_string(godzina);
		s.replace(s.begin(), s.begin() + 2, hour);
		cout << s;
	}
	

	

	return 0;
}




