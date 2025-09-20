#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;cin>>n>>m;
    int arr[n];
    int l=0;
    int ans;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if((arr[i]+m-1)/m>=l)
        {
            ans=i;
            l=(arr[i]+m-1)/m;
        }
    }
   cout <<ans+1;
    return 0;
}