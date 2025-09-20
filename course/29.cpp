#include <bits/stdc++.h>
using namespace std;



int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     char s[100];
    char t[100];
    cin>>s>>t;
    int j;
    int sl = strlen(s);
    int tl = strlen(t);

    char p[205];
    int i=0;
        for(j=0;j<sl && j<tl;j++)
        {
            p[i++]=s[j];
            p[i++]=t[j];
        }
        if(j<sl)
        {
            for(;j<sl;j++)
            p[i++]=s[j];
        }
        if(j<tl)
        {
             for(;j<tl;j++)
            p[i++]=t[j];
        }
    p[i]=0;

    cout <<p<<endl;
   }

    return 0;
}