#include <bits/stdc++.h>
using namespace std;



int main()
{
    long int a,b,c;
    long double d;
    cin>>a>>b;
    c=a-b;
    d=( (long double)c/(long double)a)*100;
    cout <<fixed<<setprecision(18)<<d;
    return 0;
}