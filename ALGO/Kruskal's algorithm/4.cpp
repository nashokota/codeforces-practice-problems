//Number of Operation to make Network Connected
#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rankSet;

// Find function with path compression
int find(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

// Union function by rank
void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rankSet[u] < rankSet[v]) {
            parent[u] = v;
        } else if (rankSet[u] > rankSet[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rankSet[u]++;
        }
    }
}

// Function to count the number of provinces
int number_of_provinces(int n, vector<vector<int>> &adj) {
    parent.resize(n);
    rankSet.resize(n, 0);

    // Initialize parent for each node
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Perform union for each connected pair
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                union_sets(i, j);
            }
        }
    }


int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    cout << "Enter the edges (0-based indexing, u v):" << endl;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    cout << "Number of Operation to make Network Connected : " << number_of_provinces(n, adj) << endl;

    return 0;
}