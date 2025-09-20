// Distance of nearest cell having 1 / 0-1 matrix
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bfs(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m));
    vector<vector<int>>dis(n,vector<int>(m));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==1)
        {
            vis[i][j]=1;
            q.push({{i,j},0});
        }
        else {
            vis[i][j]=0;
        }
    }

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int stp=q.front().second;
        q.pop();
            dis[row][col]=stp;

            for(int i=0;i<4;i++)
            {
              int nr=row+dr[i];
              int nc=col+dc[i];
              if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0)
              {
                vis[nr][nc]=1;
                q.push({{nr,nc},stp+1});
              }
            }
    }
    return dis;
}

int main()
{
    int n,m;
    cout << "Enter row and column :";
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    cout<<"Enter grid :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>ans = bfs(grid);
    cout << "Output :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}