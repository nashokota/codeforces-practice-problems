// Bellman Ford Algorithm
#include <bits/stdc++.h>
using namespace std;

void bellman(vector<pair<int,pair<int,int>>>&edge,int v,int src)
{
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    for(int i=0;i<v-1;i++)
    for(auto it:edge)
    {
        int u = it.first;
        int v = it.second.first;
        int w = it.second.second;
        if(dist[u]+w<dist[v] && dist[u]!=INT_MAX)
        {
            dist[v]=dist[u]+w;
        }
    }
    for(auto it:edge){
        int u = it.first;
        int v = it.second.first;
        int w = it.second.second;
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
        {
            cout<<"There is a negative cycle !!"<<endl;
            return ;
        }
    }

    cout << "The distances from the "<<src<<" node are : ";
    for(auto it:dist)
    {
        cout << it <<" ";
    }
}

int main()
{
    int v,e;
    cout << "Input vertices and edges :";
    cin>>v>>e;
    vector<pair<int,pair<int,int>>>edge(v);
    cout << "Input the edges (x y w)"<<endl;
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edge.push_back({x,{y,z}});
    }
    int src;
    cout << "Input the source node :";
    cin>>src;
    bellman(edge,v,src);
    return 0;
}