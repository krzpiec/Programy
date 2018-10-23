#include <iostream>
#include <cmath>

int main()
{
    int a=0; int b=0;
    std::cout << "Podaj a i b "<< std::endl;
    std::cin>>a;
    std::cin>>b;
    long double potega = pow(a,b);
    //std::cout <<potega<< std::endl;
    long double result = potega;
    while(result>10)
    {
        result = result-10;
    }
    std::cout<<result<<std::endl;
    return 0;
}
