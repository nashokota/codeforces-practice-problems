#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int arr[n+1];
    int sum=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int st,ed;cin>>st>>ed;
    if(st>ed) swap(st,ed);
    
        for(int i=st;i<=ed-1;i++)
        {
            cnt+=arr[i];
        }
    
    
    cout <<min(cnt,sum-cnt);
    return 0;
}