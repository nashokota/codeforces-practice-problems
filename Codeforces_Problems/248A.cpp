#include <bits/stdc++.h>
using namespace std;



int main()
{
 int t;cin>>t;
 int arr[t];
 int arr2[t];
 int cnt_zero1=0,cnt_one1=0,ans=0;
 int cnt_zero2=0,cnt_one2=0;
 for(int i=0;i<t;i++)
 {
    cin>>arr[i]>>arr2[i];
    if(arr[i]==0)
    {
        cnt_zero1++;
    }
    else cnt_one1++;
    if(arr2[i]==0)
    {
        cnt_zero2++;
    }
    else cnt_one2++;
 }   
 
 ans+=min(cnt_one1,cnt_zero1);
    ans+=min(cnt_one2,cnt_zero2);
    cout <<ans<<endl;
    return 0;
}