#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    int ans=0;
    int k=n;
    while(n)
    {
        k=n%10;
        n=n/10;
        if(n)
        ans+=9;
        else 
        ans+=k;
    }
    cout << ans<<endl;
}

int main()
{
 int t;cin>>t;
 while (t--)
 {
    solve();
 }   
    return 0;
}