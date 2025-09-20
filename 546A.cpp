//Soldier and Bananas
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    int x=0;
    for(int i=1;i<=w;i++)
    {
        x+= k*i;
    }
    if(x<=n)
    cout << 0;
    else
    cout << x-n;
    return 0;
}