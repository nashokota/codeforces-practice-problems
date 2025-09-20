//Cheapest Flights with K-stops
#include <bits/stdc++.h>
using namespace std;

int cheap_flight(vector<vector<pair<int,int>>>&adj,int v,int e,int src,int des,int k)
{
    queue<pair<int,pair<int,int>>>p;
    p.push({0,{src,0}});
    vector<int>dist(v,1e9);
    dist[src]=0;
    while(!p.empty())
{
    int step =p.front().first;
    int node =p.front().second.first;
    int dis =p.front().second.second;
    p.pop();
    if(step>k)continue;
    for(auto it :adj[node])
    {
        int adj_node = it.first;
        int edge_w = it.second;
        if(dist[adj_node]>dis+edge_w && step<=k)
        {
            dist[adj_node] = dis+edge_w;
            p.push({step+1,{adj_node,dist[adj_node]}});
        }
    }
}
    if(dist[des]==1e9)return -1;
    else {
        return dist[des];
    }
}

int main()
{
     int v ,e;
    cout <<"Enter vertices and edges :";
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v+1);
    cout << "Input the edges : (x y w)";
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }   
    int src,des,k;
    cout <<"Enter source node , destination & k-stops : (src des k)";
    cin>>src>>des>>k;
    int value = cheap_flight(adj,v,e,src,des,k);
    cout << "Output : "<<value <<endl;
    return 0;
}