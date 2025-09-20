#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            mp[x]++;
        }
        if(mp.size()>=3){
        cout << "NO"<<endl;
        }
        else {
            if(abs(mp.begin()->second - mp.rbegin()->second)<=1)
            {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}