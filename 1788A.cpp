#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >>n;
    int arr[n];
    int j ,cnt=0;
    int k=0;
    for ( j=0;j<n;j++)
    {
        cin>> arr[j];
        if(arr[j]==2)cnt++;
    }
   if(cnt%2==1)
   {
    cout << -1 <<endl;
    return ;
   }
   for(int i=0;i<n;i++)
   {
    if(arr[i]==2)
    {
        k++;
    }
    if(cnt/2==k)
    {
        cout <<i+1<<endl;
        return ;
    }
   }
}
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        solve();
    }
    return 0;
}