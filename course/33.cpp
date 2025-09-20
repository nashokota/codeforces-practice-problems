// counting bits 
#include <bits/stdc++.h>
using namespace std;

int func(int i)
{
    int cnt=0;
    for(int k=0;k<11;k++)
    {
        if(i>>k & 1)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+= func(i);
        }
        cout << ans << endl;
    }
    return 0;
}