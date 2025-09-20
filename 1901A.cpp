#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k=0;
    int m,x;cin>>m>>x;
    int arr[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<m-1;i++)
    {
        int o=arr[i+1]-arr[i];
        k=max(k,o);
    }
    k=max(k,arr[0]);
    k=max(k,2*(x-arr[m-1]));
    cout << k<<endl;
}

int main()
{
    int n;cin>>n;
    while(n--)
    {
        solve();
    }
    return 0;
}