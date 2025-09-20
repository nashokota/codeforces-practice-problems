#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,a,b;cin>>n;
 vector<pair<int,int>> p;
 for(int i=0;i<n;i++)
 {
    cin>>a>>b;
    p.push_back(make_pair(a,b));
 }  
 int ans=0; 
 for(int i=0;i<n;i++)
 {
    int r=0,l=0,u=0,d=0;
    for(int j=0;j<n;j++)
    {
        if(i==j) continue;

        if(p[i].first>p[j].first && p[i].second == p[j].second)
        l++;
            if(p[i].first<p[j].first && p[i].second == p[j].second)
            r++;
                if(p[i].first==p[j].first && p[i].second>p[j].second)
                d++;
                    if(p[i].first==p[j].first && p[i].second<p[j].second)
                    u++;

ans+=(l&&r&&d&&u);
         if(l&&r&&d&&u) break;           
    }
 }
 cout << ans;
    return 0;
}