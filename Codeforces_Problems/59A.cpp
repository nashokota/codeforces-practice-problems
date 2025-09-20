#include <bits/stdc++.h>
using namespace std;



int main()
{
    string a;
    cin>>a;
    int b=0,c,d;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<=90 && a[i]>=65)
        {
            b++;
        }
    }
    c=a.size();
d=c-b;
if(b>d)
{
   transform(a.begin(), a.end(), a.begin(), ::toupper); 
    cout <<a;
}
else{
   transform(a.begin(),a.end(),a.begin(),::tolower);
    cout <<a;
}
    return 0;
}