#include <bits/stdc++.h>
using namespace std;



int main()
{
    int a,b,c,d=0,e,f;
    cin>>a>>b>>c;
    d=a;
    for(;d<=b;d++)
    {
        e=d%c;
        if(e==0)
        {
            cout << d;
            f++;
            break;
        }
        else
        f=-1;

    }
    if(f==-1)
    cout <<f;

    
    return 0;
}