#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0 && m)
        {
            m--;
            ans+= abs(arr[i]);
        }
    }
    cout << ans<<endl;
    return 0;
}