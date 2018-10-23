#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
//
int main()
{


             cout << (char) ( 'g' + ('A' - 'a')) ;
    string linia;
    string liniax;
    getline(cin,linia);
    int dlugosc = linia.length();
     for(int i=0; i<=dlugosc; i++)
     {
        if(isdigit(linia[i])) {liniax+= linia[i]; }
     }
     cout<<liniax<<endl;
     int dltab = liniax.length();
     int tablica[dltab];
     for(int i=0; i<dltab;i++)
     {
        tablica[i]= liniax[i] - '0';//przekonwertowanie ascii na liczby odejmij pierwszy wyraz tych liczb
         cout<<tablica[i]<<endl;

     }
// Dlaczego tablice maja +48???????????
    return 0;
}
