#include <bits/stdc++.h>
using namespace std;



int main()
{
    //weighted graph
    int n,m;cin>>n>>m;
    int adj[n+1][m+1]={0};
    for(int i=0;i<m;i++)
    {
        int u,v,weight;
        adj[u][v]=weight;
        adj[v][u]=weight;
    }
    return 0;
}