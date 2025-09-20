#include <bits/stdc++.h>
using namespace std;



int main()
{
    char s[1000000];
    cin.get(s,1000000);

    int len = strlen(s);

    for(int i=0;i<len;i++)
    {
        if(s[i]!= '\\')
        {
            cout << s[i];
        }
        else 
        break;
    }
    cout <<endl;


    return 0;
}