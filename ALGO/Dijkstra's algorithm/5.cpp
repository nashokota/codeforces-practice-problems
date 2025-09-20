// Shortest Distance in a Binary Maze
#include <bits/stdc++.h>
using namespace std;

int short_dis(vector<vector<int>>&grid,pair<int,int>src,pair<int,int>end,int r,int c)
{
    vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
    dist[src.first][src.second]=0;
    queue<pair<int,pair<int,int>>>p;
    p.push({0,{src.first,src.second}});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!p.empty())
    {
        int dis = p.front().first;
        int row = p.front().second.first;
        int col = p.front().second.second;
        p.pop();
        for(int i=0;i<4;i++)
        {
            int newr = row + dr[i];
            int newc = col + dc[i];
            if(newr>=0&&newr<r&&newc>=0&&newc<c&&grid[newr][newc]==1&&dist[newr][newc]>dis+1)
            {
                dist[newr][newc]=dis+1;
                p.push({dist[newr][newc],{newr,newc}});
                if(newr==end.first && newc==end.second)
                return dist[newr][newc];
            }
        }
    }
    return -1;
}

int main()
{
    int r,c;
    cout << "Input row & column :";
    cin>>r>>c;
    cout <<"Input the grid :"<<endl;
    vector<vector<int>>grid(r,vector<int>(c));
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    cin>>grid[i][j];

    pair<int,int>src;
    pair<int,int>end;
    cout << "Input index of source :";
    cin>>src.first>>src.second;
    cout << "Input index of ending :";
    cin>>end.first>>end.second;
    int nn =  short_dis(grid,src,end,r,c);
    cout << "Output :"<<nn<<endl;
    return 0;
}