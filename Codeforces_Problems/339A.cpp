#include <bits/stdc++.h>
using namespace std;



int main()
{
    string a;
    cin>>a;
    
    for(int j=0;j<a.length()-1;j++)
    {
    for(int i=0;i<a.length()-j-1;i++)
    {
        if(a[i]=='+')continue;
        if(a[i]>a[i+2])
        {
          char l=a[i];
          a[i]=a[i+2];
          a[i+2]=l;
        }
    }
    }
    cout<<a;
    return 0;
}