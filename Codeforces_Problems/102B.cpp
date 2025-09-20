#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int x,y=0,z=0;
    while(n!=0)
    {
        here:
     x=n%10;
     y+=x;
     n=n/10;
    }
z++;
    if(y/10!=0)
    {
        n=y;
        goto here;
    }
    cout<<z;
    return 0;
}