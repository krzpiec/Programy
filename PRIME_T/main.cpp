#include <iostream>


int main()
{
    int a[5];
    for(int z=0; z<5; z++)
    {
        a[z]=1;
    }

    std::cout<<"Podaj 5 liczb"<<std::endl;
    int x[5];
   for(int i=0; i <5; i++)
    {
        std::cin>>x[i];
    }
  for(int y=0; y<5; y++)
  {
      for (int z=2; z<x[y]; z++)
        {
            if(x[y]%z==0) {a[y]=0;}
        }

  }
for (int p=0; p<5; p++)
{
    if(a[p]==1) {std::cout<<"Liczba "<<x[p]<<" TAK" <<std::endl;}
    else {std::cout<<"Liczba "<<x[p]<<" NIE" <<std::endl;}
}


}

