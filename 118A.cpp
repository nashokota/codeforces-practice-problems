#include <bits/stdc++.h>
using namespace std;



int main()
{
   string a,k;
    cin>>a;
    int d=a.size();
    
   for(int i=0;  i<d  ;i++)
   {
    if(a[i]!='a' && a[i]!='A' && a[i]!='e' && a[i]!='E' && a[i]!='I' && a[i]!='i' && a[i]!='O' && a[i]!='o' && a[i]!='U' && a[i]!='u' && a[i]!='Y' && a[i]!='y')
    {
        k+='.';
        k+=(char)tolower(a[i]);
    }
   }
   cout<<k;
return 0;
}


