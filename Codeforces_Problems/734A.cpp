#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin >>t;
    char s[t];
    cin>>s;
    int x=0,y=0;
    for(int i=0;i<t;i++)
    {
        if(s[i]=='A')
        {
            x++;
        }
        else 
        {
            y++;
        }
    }
    if(x>y)
    {
        cout << "Anton";
    }
    else if (x==y) cout << "Friendship";
    else 
    cout << "Danik";
    return 0;
}