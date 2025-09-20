#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int m;cin>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int xx=1;
    for(int i=0;i<n-1;i++)
    {
        if((arr[i+1]-arr[i])>m)
        {
            xx=1;
        }
        else {
            xx++;
        }
    }
    cout << xx;
    return 0;
}