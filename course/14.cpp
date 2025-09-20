#include <bits/stdc++.h>
using namespace std;



int main()
{
    int K,S;
    cin>>K>>S;
    int x=0;
    for(int i=0;i<=K;i++)
    {
        for(int j=0;j<=K;j++)
        {
           int k=S-i-j;
           if(k>=0 && k<=K)
           x++;
        }
    }
    cout <<x;
    return 0;
}