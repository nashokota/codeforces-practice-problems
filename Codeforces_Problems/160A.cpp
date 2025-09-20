#include <bits/stdc++.h>
using namespace std;



int main()
{
 vector<int>vec;
 int sum=0;
 int n;cin>>n;
 for(int i=0;i<n;i++)
 {
    int x;
    cin>>x;
    vec.push_back(x);
    sum+=x;
 }  
 sum=sum/2;
 int cnt=0; int cal=0;
 sort(vec.begin(),vec.end());
 for(int i=n-1;i>=0;i--)
 {
    cnt++;
    
   cal+=vec[i];
   if(cal>sum)break;
 }
 cout << cnt;
    return 0;
}