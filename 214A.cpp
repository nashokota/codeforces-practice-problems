#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;cin>>n>>m;
    int i,j;
    int cnt=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if((i*i+j)==n && (i+j*j)==m)
            cnt++;
        }
    }
    cout << cnt<<endl;
    return 0;
}