#include <bits/stdc++.h>
using namespace std;



int main()
{
 int n;cin>>n;
 int m;cin>>m;
 int arr[n][2*m];
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<2*m;j++)
    {
        cin>>arr[i][j];
    }
 }   
 int cnt=0;
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<2*m;j+=2)
    {
       if(arr[i][j]==1 || arr[i][j+1])
       {
        cnt++;
       }
    }
 }  
 cout <<cnt;
    return 0;
}