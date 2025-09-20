#include <bits/stdc++.h>
using namespace std;



int main()
{
    int x;cin>>x;
    int p,o,j;
    p=o=x;
    p=p/10;
    if(p>x)
    {
        x=p;
    }
    //o=x;
    j=o%10;
    o=o/100;
    o=o*10+j;
    if(o>x)
    {
        x=o;
    }
    cout << x;
    return 0;
}