/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 9: drzewo poszukiwań binarnych
 
 */

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <iostream>   // biblioteka dla strumienie wejscia/wyjscia (input/output)
#include <fstream> 
#include <sstream> 
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>

#include "funkcje.h"
 
 
 
 
int main ()
{
   // DRZEWO POSZUKIWAŃ BINARNYCH    
   
   wezel * pKorzen = nullptr;   
   
    
   for (int i : { 5, 2, 8, 1, 0, 6, 3 } /* { 1,2,3,4,5,6,7,8,9}*/)
      dodajDoDrzewaRekurencyjnie(pKorzen, i);
      
   wypisz (pKorzen);   
   std::cout << std::endl;
    
   wypisz (pKorzen, 0); 
    
   usunDrzewo(pKorzen);
   usunDrzewo(pKorzen);
   
    for (int i : { 5, 2, 8, 1, 0, 6, 3 } )
       dodajDoDrzewaIteracyjnie(pKorzen, i);
 
    wypisz (pKorzen, 0); 
    
//    
   std::cout << "rekurencyjnie" << std::endl;
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, -3, 12, -1, 7, 9 } )
   {
       auto p = znajdzRekurencynie(pKorzen, i);
       if (p)
           std::cout << "szukana wartosc: " << i << ", wartosc w znalezionym wezle: " << p->wartosc << std::endl;
       else
           std::cout << "szukana wartosc " << i << " nie wystepuje w drzewie" << std::endl;
           
   }
// 
   std::cout << "iteracyjnie" << std::endl;
   for (int i : { 5, 2, 8, 1, 0, 6, 3, 4, -3, 12, -1, 7, 9 } )
   {
       auto p = znajdzIteracyjnie(pKorzen, i);
       if (p)
           std::cout << "szukana wartosc: " << i << ", wartosc w znalezionym wezle: " << p->wartosc << std::endl;
       else
           std::cout << "szukana wartosc " << i << " nie wystepuje w drzewie" << std::endl;
           
   }
   
   std::cout << std::endl;
   std::cout << pKorzen << std::endl;  // użycie operatora << własnoręcznie zdefiniowanego
 
   usunDrzewo(pKorzen);
   usunDrzewo(pKorzen);

      
   
   return 0; 
   
} 




// hic sunt leones
