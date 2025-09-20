#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int i,j,k=0,l=0;
    int ar[n];
int ara[100005];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int sum=INT_MAX;
    for(j=0;j<n;j++)
    {
        for(i=0;i<ar[j];i++)
        {
            cin>>ara[i];
            l+=ara[i]*5;
        }
        l+=15*ar[j];
        sum=min(sum,l);
        l=0;
    }
    cout  << sum;
    return 0;
}