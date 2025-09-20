//Print the Shortest Path
#include <bits/stdc++.h>
using namespace std;

void shortest_path(vector<vector<pair<int, int>>>& adj, int v, int src, int des) {
    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, INT_MAX);
    vector<int> parent(v);

    // Initialize distances and parent nodes
    for (int i = 0; i < v; i++) parent[i] = -1;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adj_node = it.first;
            int edge_weight = it.second;

            if (dist[adj_node] > dis + edge_weight) {
                parent[adj_node] = node;
                dist[adj_node] = dis + edge_weight;
                pq.push({dist[adj_node], adj_node});
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> path;
    for (int current = des; current != -1; current = parent[current]) {
        path.push_back(current);
    }

    // Check if there is a path from src to des
    if (path.back() != src) {
        cout << "No path found from " << src << " to " << des << endl;
        return;
    }

    // Reverse the path to get the correct order from src to des
    reverse(path.begin(), path.end());

    // Print the path
    cout << "Shortest path: ";
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<pair<int, int>>> adj(v);
    cout << "Enter edges and weights (x y w): " << endl;
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});  // For undirected graph
    }

    int src, des;
    cout << "Enter source and destination: ";
    cin >> src >> des;

    shortest_path(adj, v, src, des);

    return 0;

}
