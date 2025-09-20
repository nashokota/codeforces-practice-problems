// Detect a Cycle in undirected graph using BFS (MULTIPLE CONNECTION)
#include <bits/stdc++.h>
using namespace std;


bool BFS_traversal(vector<vector<int>>&adj ,int st ,vector<bool>&vis)
{
    vis[st]=1;
    queue<pair<int,int>>q;
    q.push({st,-1});
    while(!q.empty())
    {
        int cur = q.front().first;
        int par = q.front().second;
        q.pop();

        for( auto it: adj[cur])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,cur});
            }
            else if(par != it){
                return true;
            }
        }
    }
    return false ;
}

int main()
{
    int v,e;
    cout <<"Enter vertices and edges no :";
    cin>>v>>e;
    vector<vector<int>>adj(v+1);
    for(int i=0;i<e;i++)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool>vis(v+1,false);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            if(BFS_traversal(adj,i,vis))
            {
                cout << "Its a Cycle ";
                return 0;
            }
        }
    }
    cout << "Its not a cycle ";
        return 0;
}


/*
every node for the first time -> 
    BFS ->  O(N+2E)
    space comp :  O(N)+O(N)
*/