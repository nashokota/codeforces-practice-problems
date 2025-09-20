#include <bits/stdc++.h>
using namespace std;

const int N = 150;
char s[N][N];

int n,m;

bool inside(int i,int j)
{
    if(i>=0 && i<n and j>=0 && j<m)
    {
        return true;
    }
    return false;
}

bool valid(int i,int j)
{
    if(!inside(i,j))return true;
    if(s[i][j]=='x')
    {
        return true;
    }
    else
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
       cin>>s[i];
    }
    int x,y;
    cin>>x>>y;
--x;--y;
    if(valid(x+1,y) && valid(x-1,y) && valid(x,y+1) && valid(x,y-1) && valid(x+1,y+1) && valid(x-1,y-1) && valid(x+1,y-1) && valid(x-1,y+1))
    {
        cout << "yes";
    }
    else
    cout << "no";
    return 0;
}