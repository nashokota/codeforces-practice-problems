//kruskal's algorithm
#include <bits/stdc++.h>

using namespace std;

vector<int> parent, rankSet;

// Function to find the root of a vertex (with path compression)
int find(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]); // Path compression
}

// Function to union two sets (with union by rank)
void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rankSet[u] < rankSet[v])
            swap(u, v);
        parent[v] = u;
        if (rankSet[u] == rankSet[v])
            rankSet[u]++;
    }
}

// Function to compare two edges based on their weights
bool compareEdges(const pair<pair<int, int>, int>& edge1, const pair<pair<int, int>, int>& edge2) {
    return edge1.second < edge2.second;
}

int kruskal(int n, vector<pair<pair<int, int>, int>>& edges) {
    // Sort edges by their weights
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize parent and rankSet arrays for union-find
    parent.resize(n);
    rankSet.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each node is initially its own parent
    }

    int mst_weight = 0;
    vector<pair<pair<int, int>, int>> mst;

    for (auto edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;

        // If the vertices of the edge are in different sets, add the edge to the MST
        if (find(u) != find(v)) {
            mst_weight += weight;
            mst.push_back(edge);
            union_sets(u, v);
        }
    }

    // Print the Minimum Spanning Tree (MST)
    cout << "Edges in the MST:\n";
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return mst_weight;
}

int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<pair<int, int>, int>> edges;

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({{u, v}, weight});
    }

    int mst_weight = kruskal(n, edges);
    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
