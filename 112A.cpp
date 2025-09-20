#include <bits/stdc++.h>
using namespace std;



int main()
{
    char s1[105];
    char s2[105];
    cin>>s1;cin>>s2;

    int ln = strlen(s1);

    for(int i=0;i<ln;i++)
    {
        s1[i]=tolower(s1[i]);
        s2[i]=tolower(s2[i]);
    }
    
    for(int i=0;i<ln;i++)
    {
        if(s1[i]==s2[i])
        {
            continue;
        }
        else if(s1[i]>s2[i])
        {
            cout << 1<<endl;
            return 0;
        }
        else 
        {
            cout << -1 <<endl;
            return 0;
        }
    }
    cout << 0 <<endl;
}