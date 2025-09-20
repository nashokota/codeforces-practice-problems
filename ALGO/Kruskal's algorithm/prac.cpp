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

// Kruskal's algorithm
int kruskal(int n, vector<pair<pair<int, int>, int>> &edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const pair<pair<int, int>, int> &edge1, const pair<pair<int, int>, int> &edge2) {
        return edge1.second < edge2.second;
    });

    // Initialize parent and rank
    parent.resize(n);
    rankSet.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mst_weight = 0;
    vector<pair<pair<int, int>, int>> mst;

    for (auto &it : edges) {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;

        // If u and v are not in the same set, include this edge in MST
        if (find(u) != find(v)) {
            mst_weight += w;
            mst.push_back(it);
            union_sets(u, v);
        }
    }

    return mst_weight;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges;
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u - 1, v - 1}, w}); // Convert to 0-based indexing
    }

    int mst_weight = kruskal(n, edges);
    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
