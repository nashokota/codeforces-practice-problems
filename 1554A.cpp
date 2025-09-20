#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int ans = 0;
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        ans = max(ans, (long long)arr[i]*arr[i+1]);
    }
    cout << ans <<endl;
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