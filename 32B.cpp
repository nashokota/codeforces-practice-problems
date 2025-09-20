#include <bits/stdc++.h>
using namespace std;



int main()
{
    char ss[2005];
    gets(ss);
    for(int i=0;ss[i]!= '\0';)
    {
        if(ss[i]=='.')
        {
            cout<<0;
            i++;
        }
        else if(ss[i]=='-' && ss[i+1]=='.')
        {
            cout<<1;
            i++;i++;
        }
        else if(ss[i]=='-' && ss[i+1]=='-')
        {
            cout <<2;
            i++;i++;
        }
    }
    return 0;
}