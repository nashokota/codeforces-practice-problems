#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;int ar[n];
    int d=INT_MAX;
    bool sort = true;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(i>0)
        {
            d=min(d,ar[i]-ar[i-1]);
            sort &=ar[i]>=ar[i-1];
        }
    }
    if(!sort)
    {cout <<0<<endl;return;}
    cout << d/2 +1<<endl;
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