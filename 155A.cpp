#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;cin>>t;
    int ar[t];
    int max=INT_MIN;int min=INT_MAX;
    int ans=0;
    for(int i=0;i<t;i++)
    {
        cin>>ar[i];
        
    }
    max=ar[0];
    min=ar[0];
    for(int i=0;i<t;i++)
    {
        if(max<ar[i])
        {
            ans++;
            max=ar[i];
        }
        if(min>ar[i])
        {
            ans++;
            min=ar[i];
        }
    }
    cout <<ans<<endl;
    return 0;
}