#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<32;i+=2)
    {
        int a= (n>>i) &1;
        int b= (n>>(i+1)) &1;
        swap(a,b);
        if(a)
        {
            ans+= 1<< i;
        }
        if(b)
        {
            ans+=1<<(i+1);
        }
    }
    cout <<ans<<endl;
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