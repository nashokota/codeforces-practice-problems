#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<pair<int,int>>>&adj,int v,int src,int des,int k)
{
    vector<int>dist(v+1,1e9);
    dist[src]=0;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    while(!q.empty())
    {
        int step = q.front().first;
        int node = q.front().second.first;
        int dis = q.front().second.second;
        q.pop();
        if(step>k)continue;
        for(auto it : adj[node])
        {
            int adj_node = it.first;
            int edge_w = it.second;
            if(step<=k && dist[adj_node]>edge_w+dis)
            {
                dist[adj_node]=edge_w+dis;
                q.push({step+1,{adj_node,dist[adj_node]}});
            }
        }
    }
    if(dist[des]==1e9)
    return -1;
    else 
    return dist[des]; 
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v+1);
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }   
    int src , des , k;
    cin>>src>>des>>k;
    int val = func(adj,v,src,des,k);
    cout << "Output : "<<val<<endl;
    return 0;
}