#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;cin>>t;
    string ss;
    cin>>ss;
    int x,y;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='B')
        {
            x=i;
            break;
        }
    }
    for(int j=ss.size()-1;j>=0;j--)
    {
        if(ss[j]=='B')
        {
            y=j;
            break;
        }
    }
    cout <<y-x+1<<endl;
}

int main()
{
    int n;cin>>n;
    while(n--){
    solve();
    }
    return 0;
}