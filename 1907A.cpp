#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string c,d;
    cin>>c;
d=c;



switch (c[0])
{
case 'a' :
            for(int i=0;i<7;i++)
        {
            c[0]='a'+(i+1);
            cout<<c<<endl;
        }
    break;
case 'b' :
 for(int i=0;i<=7;i++)
        {
            c[0]='a'+i;
            if(c[0]=='b')
            {
                continue;
            }
            cout<<c<<endl;
        }

    break;
case 'c' :
 for(int i=0;i<=7;i++)
        {
            c[0]='a'+i;
            if(c[0]=='c')
            {
                continue;
            }
            cout<<c<<endl;
        }

    break;
case 'd' :
 for(int i=0;i<=7;i++)
        {
            c[0]='a'+i;
            if(c[0]=='d')
            {
                continue;
            }
            cout<<c<<endl;
        }

    break;
case 'e' :
for(int i=0;i<=7;i++)
        {
            c[0]='a'+i;
            if(c[0]=='e')
            {
                continue;
            }
            cout<<c<<endl;
        }

    break;
case 'f' :
 for(int i=0;i<=7;i++)
        {
            c[0]='a'+i;
            if(c[0]=='f')
            {
                continue;
            }
            cout<<c<<endl;
        }

    break;
case 'g' :
 for(int i=0;i<=7;i++)
        {
            c[0]='a'+i;
            if(c[0]=='g')
            {
                continue;
            }
            cout<<c<<endl;
        }

    break;
case 'h' :
 for(int i=0;i<=7;i++)
        {
            c[0]='a'+i;
            if(c[0]=='h')
            {
                continue;
            }
            cout<<c<<endl;
        }

    break;
}
c=d;
// int n;
// n=(int)c[1];
// cout<<c<<" "<<d<<endl;

switch (c[1]-'0')
{
case 1 :
for(int i=0;i<=7;i++)
{
    if(i==0)continue;
    c[1]='1'+i;
    cout <<c<<endl;
}
    break;
case 2 :
for(int i=0;i<=7;i++)
{
    if(i==1)continue;
    c[1]='1'+i;
    cout <<c<<endl;
}

    break;
case 3 :
for(int i=0;i<=7;i++)
{
    if(i==2)continue;
     c[1]='1'+i;
    cout <<c<<endl;
}
    break;
case 4 :
for(int i=0;i<=7;i++)
{
    if(i==3)continue;
    c[1]='1'+i;
    cout <<c<<endl;
}
    break;
case 5 :
for(int i=0;i<=7;i++)
{
    if(i==4)continue;
    c[1]='1'+i;
    cout <<c<<endl;
}
    break;
case 6 :
for(int i=0;i<=7;i++)
{
    if(i==5)continue;
    c[1]='1'+i;
    cout <<c<<endl;
}
    break;
case 7 :
for(int i=0;i<=7;i++)
{
    if(i==6)continue;
     c[1]='1'+i;
    cout <<c<<endl;
}
    break;
case 8 :
for(int i=0;i<=7;i++)
{
    if(i==7)continue;
    c[1]='1'+i;
    cout <<c<<endl;
}
    break;

default:
    break;
}

   
}

int main()
{
    int t;
    cin>>t;
    while(t)
    {
        solve();
        t--;
    }
    return 0;
}




