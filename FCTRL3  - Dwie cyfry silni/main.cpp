#include <iostream>
int fn(int x) //rekurencyjnie
{
    if(x==1) { return 1;}
    else {return x*fn(x-1);}
}


int main()
{
    int x;
    std::cout << "Podaj cyfre" << std::endl;
    std::cin>>x;
    int silnia = 1;
    for(int i=1; i<=x; i++) //normalnie
    {
       silnia=silnia*i;
    }
   std::cout<<"Silnia to "<<silnia<<" "<<std::endl;

   int result=silnia;

   while(result>=100)
   {
       result=result-100;
   }

int j = result%10;
int d = (result-j)/10;

std::cout<<"Cyfra dziesiatek silni to: "<<d<<" "<<std::endl;
std::cout<<"Cyfra jednosc silni to: "<<j<<" "<<std::endl;

    return 0;
}
