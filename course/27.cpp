#include <bits/stdc++.h>
using namespace std;



int main()
{
    char s[1000000];
    cin>>s;
    int ln= strlen(s);

    for(int i=0;i<ln;i++)
    {
        if(s[i]==',')
        {
            s[i]=' ';
        }
     if(islower(s[i]))
        {
         s[i]=   toupper(s[i]); 
        }
        else
        {
          s[i]=  tolower(s[i]);
        }
    }

cout <<s;
    return 0;
}