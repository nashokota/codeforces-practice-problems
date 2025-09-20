//bfs traversal technique
#include <bits/stdc++.h>
using namespace std;

void BFS_traversal(vector<vector<int>>&adj,int st,vector<bool>&vis)
{
    queue<int>q;
    q.push(st);
    vis[st]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur <<" ";
        for(auto it :adj[cur])
        {
            if(!vis[it])
            {
                vis[it]=true;
                q.push(it);
            }
        }
    }
}
int main()
{
   int v,e;
   cout << "Enter the number of vetices and edges :";
   cin>>v>>e;
   vector<vector<int>>adj(v+1);
   for(int i=1;i<=e;i++)
   {
    int x,y;cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
   }
   cout << "Enter starting node :";
   int st;cin>>st;
   vector<bool>vis(v+1,false);
   BFS_traversal(adj,st,vis);
    return 0;
}