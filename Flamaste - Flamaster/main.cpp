#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    std::string linia;
    getline(std::cin,linia);
    int dlugosc = linia.length();
    std::cout<<dlugosc<<std::endl;
    for(int i=1; i<7; i=i+1)
    {
        if(linia[i]==linia[i+1]) {linia.erase(i,1);}
    }
    std::cout<<linia<<std::endl;
    return 0;
}
