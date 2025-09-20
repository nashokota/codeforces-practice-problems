#include <bits/stdc++.h>
using namespace std;



int main()
{
    int s;cin>>s;
    int n;cin>>n;
    int x,y;
  vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        arr.push_back({x,y});
    }   
    sort (arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        if(s<=arr[i].first)
        {
            cout << "NO";
            return 0;
        }
        else{
            s+=arr[i].second;
        }
    }
    cout << "YES";
    return 0;
}