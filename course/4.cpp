#include <bits/stdc++.h>
using namespace std;



int main()
{
    float a,b=0;
    cin>>a;
    b=a;
    a=a-(int)a;
    if(a>=0.5)
    {
        b=ceil(b);
    }
    else
    b=floor(b);

    cout <<b;
    return 0;
}