#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int m;cin>>m;
    vector<int>arr(m);
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int best= INT_MAX;
    for(int k=0;k<m-n+1;k++)
    {
        best = min(best, arr[k+n-1]-arr[k]);
    }
    cout << best;
    return 0;
}