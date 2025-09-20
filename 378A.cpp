#include <bits/stdc++.h>
using namespace std;



int main()
{
 int n,m;cin>>n>>m;
 int x=0,y=0,z=0;
 for(int i=1;i<=6;i++)
 {
    if(abs(n-i)>abs(m-i))
    {
        x++;
    }
    if(abs(n-i)<abs(m-i))
    {
        y++;
    }
    if(abs(n-i)==abs(m-i))
    {
        z++;
    }
 }   
 cout <<y<<" "<<z<<" "<<x;
    return 0;
}