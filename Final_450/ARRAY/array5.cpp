// Union of two array //

#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    set<int>ss;
    for(int i=0;i<n;i++)ss.insert(a[i]);
    for(int i=0;i<m;i++)ss.insert(b[i]);
    cout << ss.size()<<endl;   
    return 0;
}