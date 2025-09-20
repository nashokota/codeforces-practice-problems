#include <bits/stdc++.h>
using namespace std;



int main()
{
    int l,b,c=0;
    cin>>l>>b;
    while(l<=b)
    {
        c++;
        l=l*3;
        b=b*2;
    }  
    cout <<c; 
    return 0;
}