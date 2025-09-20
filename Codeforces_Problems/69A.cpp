#include <bits/stdc++.h>
using namespace std;



int main()
{
    int a;
    cin>>a;
    int ar1[a],ar2[a],ar3[a];
    for(int i=0;i<a;i++)
    {
        cin>>ar1[i];
        cin>>ar2[i];
        cin>>ar3[i];
    }
    
    int m=0,n=0,l=0;
    for(int i=0;i<a;i++)
    {
       m=m+ar1[i];
       n+=ar2[i];
       l+=ar3[i];
    }
    if(m==0 && n==0 && l==0)
    {
        cout <<"YES";
    }
    else
    cout<<"NO";
    return 0;
}