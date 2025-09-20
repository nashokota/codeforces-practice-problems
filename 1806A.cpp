#include <bits/stdc++.h>
using namespace std;

void solve()
{
   long long int a,b,c,d;cin>>a>>b>>c>>d;
   long long int ans=0;
    if(a==c && b==d){cout <<0<<endl;return;}
    if(b<d)
    {
        ans=d-b;
        a=a+ans;
        if(a<c){cout <<-1<<endl;return;}
        ans+=abs(a-c);
    }
    else if(b==d) {
        if(a>c)
        ans=abs(a-c);
        else 
        ans=-1;
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