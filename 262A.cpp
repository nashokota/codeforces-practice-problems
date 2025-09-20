#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,k,t=0,tt=0,ans=0;
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        while(ar[i])
        {
            tt=ar[i]%10;
            ar[i]=ar[i]/10;
            if(tt==4 || tt==7){
                t++;
            }
        }
        if(t<=k){ans++;}
        t=0;
    }   
    cout << ans;
    return 0;
}