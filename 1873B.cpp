#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m=0;
    int j;
  int n;
  cin>>n;
  int arr[n];
  for (int i=0;i<n;i++)
  {
    cin>> arr[i];
  }
  sort(arr,arr+n);
  int sum=1;
  for(j=0;j<n;j++)
  {
    if(j==0)
    {
        arr[j]=arr[j]+1;
    }
    
    sum*=arr[j];
  }
  cout << sum <<endl;
//   if(m==1)
//   {
//     cout << sum<<endl;
//   }
//   else{
//     sum=sum/arr[j-1]+sum*(arr[j-1]+1);
//     cout << sum<<endl;
//   }

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
    return 0;
}