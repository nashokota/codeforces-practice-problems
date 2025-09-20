//Path with minimum effort 
#include <bits/stdc++.h>
using namespace std;

int min_effort(vector<vector<int>>&grid)
{
    int r=grid.size();
    int c=grid[0].size();

    vector<vector<int>>dist(r,vector<int>(c,1e9));
    dist[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!pq.empty())
    {
        int dis =pq.top().first;
        int row =pq.top().second.first;
        int col =pq.top().second.second;
        pq.pop();
        if(row==r-1 && col==c-1) return dis;
        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<r&&nc>=0&&nc<c&& max(abs(grid[row][col]-grid[nr][nc]),dis)<dist[nr][nc])
            {
               dist[nr][nc] = max(abs(grid[row][col]-grid[nr][nc]),dis);
               pq.push({dist[nr][nc],{nr,nc}});
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

int effort = min_effort(grid);

cout <<"Output :"<<effort<<endl;

    return 0;
}