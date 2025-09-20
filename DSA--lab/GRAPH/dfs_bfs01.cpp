//Number of Province

#include <bits/stdc++.h>
using namespace std;

void BFS_traversal(vector<vector<int>>&adj,int v,int st,vector<bool>&vis)
{
   
    queue<int>q;
    q.push(st);
    vis[st]=true;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
     //   cout << current<<" ";
        for(auto it:adj[current])
        {
            if(!vis[it])
            {
               // cout << it <<" ";
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
    vector<bool>vis(v+1,false);
  int cnt=0;
  for(int i=1;i<=v;i++)
  {
    if(!vis[i])
    {
        cnt++;
         BFS_traversal(adj,v,i,vis);
    }
  }
   cout << "Total Province :"<<cnt<<endl;
    return 0;
}

/*
using dfs ,
time complexity -> O(N) + O(v+2E)
space complexity -> O(N) + O(N)

*/