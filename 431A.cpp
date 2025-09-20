#include <bits/stdc++.h>
using namespace std;



int main()
{
 int a,b,c,d;cin>>a>>b>>c>>d;
 string ss;cin>>ss;
 int cnt=0;
 for(int i=0;i<ss.size();i++)
 {
    if((ss[i]-'0')==1)cnt+=a;
    if((ss[i]-'0')==2)cnt+=b;
    if((ss[i]-'0')==3)cnt+=c;
    if((ss[i]-'0')==4)cnt+=d;

 }   
 cout <<cnt;
    return 0;
}