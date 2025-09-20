#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;
    char s[n];
    cin>>s;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(i+1 <=n and s[i]=='R' and s[i+1]=='R')
        {
            k++;
        }
         if(i+1 <=n and s[i]=='G' and s[i+1]=='G')
        {
            k++;
        }
         if(i+1 <=n and s[i]=='B' and s[i+1]=='B')
        {
            k++;
        }
    }
    cout << k <<endl;
    return 0;
}