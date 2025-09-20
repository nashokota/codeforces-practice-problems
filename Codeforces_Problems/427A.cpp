#include <bits/stdc++.h>
using namespace std;



int main()
{
 int n;cin>>n;
 int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int pol=0;
    int cri=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1) {
            cri++;
            if(pol>0)
            {
                cri--;
                pol--;
            }
        }
        else {
            pol+=arr[i];
        }
    }
    cout <<cri;
    return 0;
}