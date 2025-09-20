#include <bits/stdc++.h>
using namespace std;

int is_beautiful(int n)
{
    int t=n;
    int d4=n%10;
    n=n/10;
    int d3=n%10;
    n=n/10;
    int d2=n%10;
    n=n/10;
    int d1=n%10;
    n=n/10;

    if(d4!=d3 && d4!=d2 && d4!=d1 && d3!=d2 && d3!=d1 && d2!=d1)
    {
        return t;
    }
    else 
    {
        t++;
        is_beautiful(t);
    }
}

int main()
{
    int n;
    cin>>n;
    int d = is_beautiful(n+1);
    cout << d;
    return 0;
}