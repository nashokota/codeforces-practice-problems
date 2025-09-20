#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,t;cin>>n>>t;
    int arr[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>t)
        {
            ans+=2;
        }
        else 
        {
            ans++;
        }
    }
    cout << ans<<endl;
    
    return 0;
}