#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            cout<<arr[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}