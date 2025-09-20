#include <bits/stdc++.h>
using namespace std;



int main()
{
 int n;cin>>n;
 int arr[n][2];
 for(int i=0;i<n;i++)
 {
    cin>>arr[i][0];
    cin>>arr[i][1];
 }   
int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i][0]==arr[j][1])
            {
                cnt++;
            }
            if(arr[i][1]==arr[j][0])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}