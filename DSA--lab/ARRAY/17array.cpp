//another missing element`s method //
#include <bits/stdc++.h>
using namespace std;



int main()
{
    int ar[]={3,7,4,9,12,6,1,11,2,10};
    int n=sizeof(ar)/sizeof(ar[0]);
    int ar1[13]={0};
    for(int i=0;i<n;i++)
    {
        int t=ar[i];
        ar1[t]++;
    }
    for(int i=0;i<13;i++)
    {
        if(ar1[i]==0)
        {
            cout << " missing element :"<< i <<endl;
        }
    }
    return 0;
}