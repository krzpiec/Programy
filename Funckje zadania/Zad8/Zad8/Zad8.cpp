
//Zad --> Dwa wektory zawierajace N posortowanych liczb pseudolosowych int bez powtorzen, wektor 'result' jest posortowany,zawiera liczby wektora 1 ktore nie zawieraja sie w wektorze 2
// Wypisac wektor 1, 2 , result i odwrocony result, nastepnie wypisac liczby pierwsze zawarte w wektorze 1 i 2
// Liczba N powstaje poprzez pomnozenie wartosci wektora liczb pierwszych, nastepnie dokonac operacji odwrotnej -> liczbe przedstawic jako iloczyn liczb pierwszych nie uzywajac poprzednich danych

#include "pch.h"
#include <iostream>
#include <chrono>
#include <random>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "Funkcje.h"

int main()
{
	fill(myvec, ile, min, max);
	fill(myvec1, ile, min, max);
	sort(myvec);
	sort(myvec1);
	print(myvec, ile); //
	print(myvec1, ile);//
	std::cout << std::endl;
	repetition(myvec, myvec1, result);
	sort(result);
	print(result, ile);//
	reverse(result);
	print(result, ile);//
	std::cout << std::endl;
	prime(myvec, primes);

	if (primes.size() != 0)
	{
		print(primes, ile);//
	}
	else
	{
		std::cout << " Brak liczb pierwszych w wektorze 1" << std::endl;
	}

	prime(myvec1, primes1);

	if (primes1.size() != 0)
	{
		print(primes1, ile);//
	}
	else
	{
		std::cout << " Brak liczb pierwszych w wektorze 2" << std::endl; 
	}

	if ((primes.size() == 0) && (primes1.size() == 0))
	{
		return 0;
	}

	merge(primes, primes1, primesmerge);
	sort(primesmerge);
	std::cout << std::endl;
	usunpowt(primesmerge);
	print(primesmerge, ile);//
	std::cout <<"liczba: "<< liczba(primesmerge, prime1)<<" " << std::endl;

	generate(ciag, prime1);

	prime(ciag, ciag2);
	print(ciag2, ile);

}