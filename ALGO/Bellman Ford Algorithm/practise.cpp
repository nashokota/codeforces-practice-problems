#include <bits/stdc++.h>
using namespace std;

void print_cycle(int start ,vector<int>&par)
{
    int cur = start;
    vector<int>cycle;
    cycle.push_back(cur);
    while(1){
        cur = par[cur];
        cycle.push_back(cur);
        if(cycle.size()>1 && cur==start)break;
    }
    reverse(cycle.begin(),cycle.end());
    cout << "Negative weighted cycle: ";
    for(auto it:cycle)
    cout << it<<" ";
    cout <<endl;
}

void bellman(vector<pair<int,pair<int,int>>>&edges,int v,int src)
{
    vector<int>dist(v,INT_MAX);
    vector<int>par(v,-1);

    dist[src]=0;

    for(int i=0;i<v-1;i++)
    {
        for(auto it:edges)
        {
            int u = it.first;
            int v = it.second.first;
            int w = it.second.second;
            if(dist[u]+w<dist[v] && dist[u]!= INT_MAX)
            {
                par[v]=u;
                dist[v]=dist[u]+w;
            }
        }
    }
    int start =-1;
    for(auto it:edges)
        {
            int u = it.first;
            int v = it.second.first;
            int w = it.second.second;
            if(dist[u]+w<dist[v] && dist[u]!= INT_MAX)
            {
                cout << "There is a negative cycle !!"<<endl;
                start = v;
                break;
            }
        }
        if(start!= -1){
            cout << "Printing the inner loop :(start=par[start])";
            for(int i=0;i<v;i++){
            start = par[start];
            cout<<start<<endl;
            }
            print_cycle(start,par);
        }
        else{
    cout << "The distance from the "<<src<<" node are : ";
    for(auto it:dist)
    cout<<it<<" ";
        }
}

int main()
{
    int v,e;
    cin >>v>>e;
    vector<pair<int,pair<int,int>>>edges(v);
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({x,{y,z}});
    }
    int src;
    cin>>src;
    bellman(edges,v,src);
    return 0;
}