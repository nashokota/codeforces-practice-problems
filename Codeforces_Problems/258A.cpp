#include <bits/stdc++.h>
using namespace std;



int main()
{
    char s[100005];
    cin>>s;
    int len = strlen(s);
    int n=-1;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0')
        {
            n=i;
            break;
        }
    }
    if(n==-1)
    {
        for(int i=0;i<len-1;i++)
        {
            cout << s[i];
        }
    }
    else {
        for(int i=0;i<len;i++)
        {
            if(i==n)
            {
                continue;
            }
            cout << s[i];
        }
    }
    return 0;
}