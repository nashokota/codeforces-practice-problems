#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(x==y)
    {
    cout<<z;
    
    }
    else if(y==z)
    {
        cout <<x;
        
    }
    else if(z==x)
    {
        cout<<y;
        
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
        cout <<endl;
    }

    return 0;
}