#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    int arr[n-1];
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
        ans+=arr[i];
    }
    cout << (-1)*ans<<endl;

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