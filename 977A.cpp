#include <bits/stdc++.h>
using namespace std;



int main()
{
    int a,b;
    cin>>a>>b;
    int n=0,m=0;
    while(b!=0){
    if(a%10 != 0)
    {
        a--;
        b--;
    }
    else 
    {
        a=a/10;
        b--;
    }
    }
    cout<<a;
    return 0;
}