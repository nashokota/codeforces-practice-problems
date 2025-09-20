// Detect cycle by DFS
#include <bits/stdc++.h>
using namespace std;

bool DFS_traversal(vector<vector<int>>&adj,vector<bool>&vis,int st)
{
    vis[st]=true;
    stack<pair<int,int>>s;
    s.push({st,-1});
    while(!s.empty())
    {
        int cur = s.top().first;
        int par = s.top().second;
        s.pop();
        for(auto it :adj[cur])
        {
            if(!vis[it])
            {
                vis[it]=true;
                s.push({it,cur});
            }
            else{
                if(par != it)
                {
                    return true ;
                }
            }
        }
    }
    return false ;
}

int main()
{
    int v,e;
    cout <<"Enter vertices and edges :";
    cin>>v>>e;
    vector<vector<int>>adj(v+1);
    for(int i=0;i<e;i++)
    {
        int x,y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool>vis(v+1,false);
    int st;
    cout <<"Enter starting node :";
    cin>>st;

    DFS_traversal(adj,vis,st)?cout << "Its a Cycle":cout <<"Its not a Cycle";
    return 0;
}