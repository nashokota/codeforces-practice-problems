// number of island

#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    while (!q.empty()) {
         row = q.front().first;
         col = q.front().second;
        q.pop();

        for (int dr = -1; dr < 2; dr++) {
            for (int dc = -1; dc < 2; dc++) {
                int new_row = row + dr;
                int new_col = col + dc;
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == '1' && !vis[new_row][new_col]) {
                    vis[new_row][new_col] = 1;
                    q.push({new_row, new_col});
                }
            }
        }
    }
}

int numIsland(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!vis[row][col] && grid[row][col] == '1') {
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cout << "Number of rows and columns: ";
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    cout << "Enter the grid:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int number_of_island = numIsland(grid);
    cout << "Number of islands: " << number_of_island << endl;
    return 0;
}

