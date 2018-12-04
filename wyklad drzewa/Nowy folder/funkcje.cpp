/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 9: drzewo poszukiwań binarnych
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl


#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>

#include "funkcje.h"

 
wezel * znajdzIteracyjnie (wezel * pRoot, const typ & wartosc)
{
    if (not pRoot or pRoot->wartosc == wartosc)
        return pRoot;
    else
    {
        auto p = pRoot;
        while (p)
        {
            if (wartosc == p->wartosc)
                return p;
            if (wartosc < p->wartosc)
                p = p->pLewy;
            else
                p = p->pPrawy;
        }
        // nie znaleźliśmy
        return nullptr;
    }
}

wezel * znajdzRekurencynie (wezel * pRoot, const typ & wartosc)
{
    if (not pRoot or pRoot->wartosc == wartosc)
        return pRoot;
    else // w drzewie cos jest
    {
        if (wartosc < pRoot->wartosc) // idziemy w lewo
            return znajdzRekurencynie(pRoot->pLewy, wartosc);
        else
            return znajdzRekurencynie(pRoot->pPrawy, wartosc);
    }
}

void dodajDoDrzewaIteracyjnie (wezel * & pRoot, typ & wartosc)
{
    if (not pRoot)
        pRoot = new wezel { wartosc, 0, 0 };
    else // w drzewie juz cos jest 
    {
        auto p = pRoot;
        
        while (p)
        {
            if (wartosc < p->wartosc) // idziemy w lewo
            {
                if (p->pLewy)  // jezeli istnieje pLewy
                    p = p->pLewy; 
                else 
                {
                    p->pLewy = new wezel { wartosc, 0, 0 };
                    p = nullptr; // można dać return;
//                     return;
                }        
            }
            else  // idziemy w prawo
            {
                if (p->pPrawy)
                    p = p->pPrawy;
                else
                {
                    p->pPrawy = new wezel { wartosc, 0, 0 };
                    p = nullptr; // można dać return;
//                     return;
                }
            }
        }
    }
    
}

void usunDrzewo (wezel * & pRoot)
{
    if (pRoot)
    {
        usunDrzewo(pRoot->pLewy);
        usunDrzewo(pRoot->pPrawy);
        
        delete pRoot;
        pRoot = nullptr;
    }
}
 
 
void dodajDoDrzewaRekurencyjnie (wezel * & pRoot, const typ & wartosc)
{
    if (not pRoot) // drzewo puste
        pRoot = new wezel { wartosc, nullptr, nullptr };
    else  // w drzewie juz co jest
    {
        if (wartosc < pRoot->wartosc) // idziem w lewo
            dodajDoDrzewaRekurencyjnie(pRoot->pLewy, wartosc);
        else // idziemy w prawo
            dodajDoDrzewaRekurencyjnie(pRoot->pPrawy, wartosc);
    }
}


void wypisz (wezel * pRoot)
{
    if (pRoot)  // jezeli drzewo jest niepuste
    {
        wypisz(pRoot->pLewy);
        std::cout << pRoot->wartosc << std::endl;
        wypisz(pRoot->pPrawy);
    }
}

void wypisz (wezel * pRoot, int wciecie)
{
    const int MNOZNIK = 4; 
    if (pRoot)  // jezeli drzewo jest niepuste
    {
        wypisz(pRoot->pLewy, wciecie + 1);
        std::cout << std::setw (wciecie * MNOZNIK) << pRoot->wartosc << std::endl;
        wypisz(pRoot->pPrawy, wciecie + 1);
    }
}

std::ostream & operator << (std::ostream & ss, wezel * pRoot)
{
    const int SZEROKOSC = 4;
    if (pRoot)
    {
        ss << pRoot->pLewy;
        ss << std::setw(SZEROKOSC) << pRoot->wartosc;
        ss << pRoot->pPrawy;
    }
    return ss;
}

