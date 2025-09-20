//Shortest Path in Undirected Graph with Unit Weights

#include <bits/stdc++.h>
using namespace std;

void shortest_path(vector<vector<int>>&adj,int v,int e,int src)
{
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        for(auto it :adj[node])
        {
            if(dist[it]>dist[node]+1)
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
   cout << "Shortest Path :";
   for(int i=0;i<v;i++)
   {
    cout << dist[i]<<" ";
   }
    
}

int main()
{
    int v ,e;
    cout <<"Enter vertices and edges :";
    cin>>v>>e;
    vector<vector<int>>adj(v+1);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
    cout << "Input source :"<<endl;
    int src;cin>>src;
    shortest_path(adj,v,e,src);
    // cout <<"Shortest Path :"<<endl;
    // for(int i=0;i<v;i++)
    // {
    //     cout << ans[i]<<" ";

    // }
    return 0;
}