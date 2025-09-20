#include <bits/stdc++.h>
using namespace std;



int main()
{
    char  s[10000] ,t[100000];
    cin>>s;
    cin>>t;
int x =strlen(s);
int y= strlen(t);
    cout << x<< " "<<y<<endl;

    for(int i=0;i<x;i++)
    {
        cout<< s[i];
    }
    cout << " ";
    for(int j=0;j<y;j++)
    {
        cout << t[j];
    }
    return 0;
}