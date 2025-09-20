#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long int xy,yz,zx;
    cin>>xy>>yz>>zx;
    long long int xyz = xy*yz*zx;
    long long int x,y,z;
    z= sqrt(xyz/(xy*xy));
    x= sqrt(xyz/(yz*yz));
    y= sqrt(xyz/(zx*zx));
    cout << 4*(x+y+z);
    return 0;
}