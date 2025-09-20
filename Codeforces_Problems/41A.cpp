#include <bits/stdc++.h>
using namespace std;



int main()
{
    char s[100005];
    char t[100005];
    cin>>s>>t;
    int ln = strlen(s);
    for(int i=0,j=ln-1;i<ln;i++,j--)
    {
        if(s[i]==t[j])
        {
            continue;
        }
        else
        {
            cout << "NO"<<endl;
            return 0;
        }
    }
    cout <<"YES"<<endl;
    return 0;
}