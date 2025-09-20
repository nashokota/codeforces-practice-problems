#include <bits/stdc++.h>
using namespace std;



int main()
{
    int k;cin>>k;
    vector<int> arr(12);
    for(int i=0;i<12;i++)
    {
        cin>>arr[i];
    }    
    int cnt=0;
    int c=0;
    sort(arr.begin(),arr.end(),greater<int>());

    for(int i=0;i<12;i++)
    {
      if(k>0)
      {
        k=k-arr[i];
        cnt++;
      }
    }    
    if(k<=0)
    cout << cnt<<endl;
    else
    cout <<-1;
    return 0;
}