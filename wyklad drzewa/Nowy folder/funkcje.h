/** @file */

/*
PODSTAWY PROGRAMOWANIA KOMPUTERÓW
 
wykład 9: drzewo poszukiwań binarnych

 */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream> 

/** Typ użyty w drzewie poszukiwań binarnych. */
typedef int typ;  // będziemy mogli łatwo zmienić typ przechowywany w liście


/** węzeł drzewa poszukiwań binarnych */
struct wezel
{
   typ wartosc;     ///< wartość przechowywana w węźle   
   wezel * pLewy,   ///< wskaźnik na lewy potomek
         * pPrawy;  ///< wskaźnik na prawy potemek
};  // <--- średnik jest niezbędny


/** Funkcja dodaje rekurencyjnie do drzewa element.
 @param pRoot korzeń drzewa
 @param wartosc wartość do dodania
 */
void dodajDoDrzewaRekurencyjnie (wezel * & pRoot, const typ & wartosc);

/** Funkcja dodaje iteracyjnie do drzewa element.
 @param pRoot korzeń drzewa
 @param wartosc wartość do dodania
 */
void dodajDoDrzewaIteracyjnie (wezel * & pRoot, typ & wartosc);


/** Funkcja wypisuje w porządku wartości przechowywane w elementach drzewa.
 @param pRoot korzeń drzewa
 */
void wypisz (wezel * pRoot);

/** Funkcja wypisuje w porządku wartości przechowywane w elementach drzewa. Kolejne warstwy drzewa są wypisywane coraz większym wcięciem.
 @param pRoot korzeń drzewa
 @param wciecie początkowe wcięcie
 */
void wypisz (wezel * pRoot, int wciecie);

/** Funkcja usuwa całe drzewo z pamięci.
@param pRoot korzeń drzewa do usunięcia, po usunięciu ma wartość nullptr */
void usunDrzewo (wezel * & pRoot);

/** Funkcja wyszukuje (rekurencyjnie) element o podanej wartości w drzewie o podanym korzeniu. 
@param pRoot korzeń drzewa
@param wartosc wartość do wyszukania
@return adres węzła przechowujący szukaną wartość, gdy nie ma takiego węzła, funkcja zwraca nullptr.
*/
wezel * znajdzRekurencynie (wezel * pRoot, const typ & wartosc);

/** Funkcja wyszukuje (iteracyjnie) element o podanej wartości w drzewie o podanym korzeniu. 
@param pRoot korzeń drzewa
@param wartosc wartość do wyszukania
@return adres węzła przechowujący szukaną wartość, gdy nie ma takiego węzła, funkcja zwraca nullptr.
*/
wezel * znajdzIteracyjnie (wezel * pRoot, const typ & wartosc);

/** Operator do latwego wypisywania drzewa.
@param ss strumień do zapisu
@param pRoot korzeń drzewa
@return zmodyfikowany strumień */
std::ostream & operator << (std::ostream & ss, wezel * pRoot);

#endif
