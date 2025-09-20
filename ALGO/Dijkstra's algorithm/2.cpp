// Dijkstra's algorithm using Priority Queue
#include <bits/stdc++.h>
using namespace std;

void dijktstra(vector<vector<pair<int,int>>>&adj,int v,int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //creating a min heap 
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for(auto it : adj[node])
        {
            int edge_weight = it.second;
            int adj_node =it.first;
            if(dist[adj_node]> dis + edge_weight)
            {
                dist[adj_node] = dis + edge_weight;
                pq.push({dist[adj_node],adj_node});
            }
        }
    }
    cout << "Output distance :";
    for(int i=0;i<v;i++)
    {
        cout <<dist[i]<<" ";
    }
}

int main()
{
    int v,e;
    cout << "Enter vertices and edges :";
    cin>>v>>e;
    cout << "Enter the Edges and weight :(x y w)";
    vector<vector<pair<int,int>>>adj(v);
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    cout << "Enter Source Node :";
    int src;cin>>src;

    dijktstra(adj,v,src);
    return 0;
}