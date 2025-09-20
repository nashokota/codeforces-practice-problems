#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int nn;cin>>nn;
    int p=0,n=0;
    for(;nn--;)
    {
        int x;cin>>x;
        if(x>0)
        p++;
        else 
        n++;
    }
    int ans=0;
    while(n>p){
        p++;n--;ans++;
    }
    if(n%2==1)ans++;
    cout <<ans <<endl;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}