//Flood fill algorithm
#include <bits/stdc++.h>
using namespace std;

void dfs(int row , int col ,int delr[],int delc[], int newCol , vector<vector<int>>&image,vector<vector<int>>&ans2,int iniCol)
{
    ans2[row][col]=newCol;
    int n=image.size();
    int m=image[0].size();

    for(int i=0;i<4;i++)
    {
        int newr=row+delr[i];
        int newc=col+delc[i];
        if(newr>=0&&newr<n&&newc>=0&&newc<m&&ans2[newr][newc]!=newCol&&image[newr][newc]==iniCol)
        {
            dfs(newr,newc,delr,delc,newCol,image,ans2,iniCol);
        }
    }

}

vector<vector<int>> Flood_fill(vector<vector<int>>&image,int sr,int sc,int newCol)
{
    vector<vector<int>> ans2 = image;
    int iniCol = image[sr][sc];
    int delr[4] ={-1,0,1,0};
    int delc[4] ={0,1,0,-1};

    dfs(sr,sc,delr,delc,newCol,image,ans2,iniCol);

    return ans2;
}

int main()
{
    cout << "Enter number of row & column :";
    int n,m;cin>>n>>m;
    cout << "Enter the grid :";
    vector<vector<int>>image(n,vector<int>(m));

    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<m ;j++)
        {
            cin>>image[i][j];
        }
    }

    cout << "Enter index of starting row & column :";
    int sr,sc;cin>>sr>>sc;
    cout << "Enter the new colour :";
    int newCol;cin>>newCol;
    
    vector<vector<int>>ans =Flood_fill(image,sr,sc,newCol);

    cout <<"Output :"<<endl;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
    {
        cout << ans[i][j]<<" ";
    }
    cout <<endl;
    }
    return 0;
}