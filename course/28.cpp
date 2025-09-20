#include <bits/stdc++.h>
using namespace std;

void solve()
{
   
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[1000];
    cin>>s;
    bool func = false;
    int ln = strlen(s);

    for(int i=0;i<ln;i++)
    {
        if(i+2<ln and s[i]=='0' && s[i+1]=='1' && s[i+2]=='0')
        func = true;
        if(i+2<ln and s[i]=='1' && s[i+1]=='0' && s[i+2]=='1')
        func = true;
    }
    if(func) cout << "Good"<<endl;
    else cout <<"Bad"<<endl;
    }
    return 0;
}