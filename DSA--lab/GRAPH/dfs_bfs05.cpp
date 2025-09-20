//Rotten Orranges

#include <bits/stdc++.h>
using namespace std;

int bfs_traverse(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cntf = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            } else {
                vis[i][j] = 0;
            }
            if (grid[i][j] == 1) {
                cntf++;
            }
        }
    }
    
    int tm = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int cnt = 0;
    
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 2 && grid[nr][nc] == 1) {
                q.push({{nr, nc}, t + 1});
                vis[nr][nc] = 2;
                cnt++;
            }
        }
    }
    
    if (cnt != cntf) {
        return -1;
    } else {
        return tm;
    }
}

int main() {
    int n, m;
    cout << "Number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << "Total time taken: " << bfs_traverse(grid) << endl;
    return 0;
}
