//dfs traversal using recursion 
#include <bits/stdc++.h>
using namespace std;

void DFS_TRAVERSAL(vector<vector<int>>&adj,int st,vector<bool>&vis)
{
    if(!vis[st])
    {
        vis[st]=true;
        cout << st << " ";
    }
    for(auto it: adj[st])
    {
        if(!vis[it])
        {
            DFS_TRAVERSAL(adj,it,vis);
        }
    }
}

int main()
{
    int v,e;
    cout << "Enter the number of total vertices and edge  :";
    cin>>v>>e;
    vector<vector<int>>adj(v+1);
    for(int i=0;i<e;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "Enter the starting Node :";
    int st;cin>>st;
    vector<bool>vis(v+1,false);
    DFS_TRAVERSAL(adj,st,vis);
    return 0;
}
