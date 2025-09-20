#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int p=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]>=arr[k-1])
        {
          
            if(arr[j]!=0)
            p++;
        }
    }
    cout << p;
    return 0;
}