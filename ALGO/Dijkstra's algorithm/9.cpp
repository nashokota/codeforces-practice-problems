//Number of Ways to Arrive at Destination
#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<pair<int,int>>>&adj,int n,int src,int des)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n,INT_MAX);
    vector<int>ways(n,0);
    dist[0]=0;ways[0]=1;
    pq.push({0,0});
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node])
        {
            
        }
    }
}

int main()
{
    int v,e;
    cout << "Input number of vertices and edges:";
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v+1);
    cout << "Input the edges : (x y w)";
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int n,src,des;
    cout << "Input n , source and destination :";
    cin>>n>>src>>des;
    int result = func(adj,n,src,des);
    cout <<"Output : "<<result<<endl;
    return 0;
}