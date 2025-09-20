//dfs traversal tecnique
#include <bits/stdc++.h>
using namespace std;

void DFS_traversal(vector<vector<int>>&adj,int v,int st)
{
    vector<bool>vis(v+1,false);
    stack<int>s;
    s.push(st);
    vis[st]=true;
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout<< cur<<" ";
        for(auto it:adj[cur])
        {
            if(!vis[it])
            {
               // cout <<it << " ";
                vis[it]=true;
                s.push(it);
            }
        }
    }
}

int main()
{
    int v,e;
    cout <<"Enter the number of vertices and edges :";
    cin>>v>>e;
    vector<vector<int>>adj(v+1);
    for(int i=0;i<e;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "Enter starting node :";
    int st;cin>>st;
    DFS_traversal(adj,v,st);
    return 0;
}