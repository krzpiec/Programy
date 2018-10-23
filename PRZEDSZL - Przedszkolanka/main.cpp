#include <iostream>

using namespace std;

int main()
{
    cout << "Podaj liczbe osob w klasach" << endl;
    int x,y;
    cin>>x; cin>>y;
    int a = x;
    int b = y;
    while(a!=b)
    {
        if(a>b) {a=a-b;}
        else {b=b-a;}
    }

    int nwd = a;
    int cukx = x/nwd;
    int cuky = y/nwd;
    int sumacuk = (cukx*y);

   cout<<"Przedszkolanka potrzebuje "<<sumacuk<<" cukierkow. Grupa 1 dostanie po "<<cuky<<", grupa 2 po "<<cukx<<" "<<endl;

    return 0;
}
