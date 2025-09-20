#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;  // Sort edges by weight
    }
};

vector<int> parent, rankSet;  // Renamed rank to rankSet

// Function to find the root of a vertex (with path compression)
int find(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);  // Path compression
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

int kruskal(int n, vector<Edge>& edges) {
    // Sort edges by their weights
    sort(edges.begin(), edges.end());

    // Initialize parent and rankSet arrays for union-find
    parent.resize(n);
    rankSet.resize(n, 0);  // Changed from rank to rankSet
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Each node is initially its own parent
    }

    int mst_weight = 0;
    vector<Edge> mst;

    for (Edge e : edges) {
        // If the vertices of the edge are in different sets, add the edge to the MST
        if (find(e.u) != find(e.v)) {
            mst_weight += e.weight;
            mst.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    // Print the Minimum Spanning Tree (MST)
    cout << "Edges in the MST:\n";
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    return mst_weight;
}

int main() {
    int n = 4;  // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mst_weight = kruskal(n, edges);
    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
