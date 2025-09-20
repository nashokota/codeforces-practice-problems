#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int arr[n];
    int m=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        m+=arr[i];
    }
    for(int i=1;i<=5;i++)
    {
        if((m+i)%(n+1)!=1)
        ans++;
        
    }
    cout <<ans;
    return 0;
}