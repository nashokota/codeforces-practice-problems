#include <bits/stdc++.h>
using namespace std;

void solve_it()
{
    char aar[8][8];
    vector<int> r;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>aar[i][j];
            if(aar[i][j]== 'R')
            {
                r.push_back(i);
            }
        }
    }
    for(int jj: r)
    {
        bool ok = true;
        for(int j=0;j<8;j++)
        {
            if(aar[jj][j] != 'R')
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout << "R\n";return;
        }
    }
    cout << "B\n";
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        solve_it();
    }
    return 0;
}