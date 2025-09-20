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
 for(int i=0;i<n;i++)
 {
    if(arr[i]>=m)
    {
        cout <<"NO";
        return 0;
    }
 }
 cout << "YES";
    return 0;
}