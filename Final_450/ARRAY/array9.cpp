// Minimise the maximum difference between heights [V.IMP]

#include <bits/stdc++.h>
using namespace std;



int main()
{
 int k,n;cin>>k>>n;
 int ar[n];
 for(int i=0;i<n;i++)
 {
    cin>>ar[i];
 }   
 sort(ar,ar+n);
 ar[n-1]=ar[n-1]+k;int i;
 for(i=0;i<n;i++)
 {
    ar[i]=ar[i]-k;
    if(ar[i]>=0)
    break;
 }
 cout << ar[n-1] - ar[i]<<endl;
    return 0;
}