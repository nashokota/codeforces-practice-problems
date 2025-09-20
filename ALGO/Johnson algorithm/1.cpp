#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <tuple>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int u, v, weight;
};

// Bellman-Ford algorithm to detect negative weight cycles and find shortest paths
bool bellmanFord(int V, const vector<Edge>& edges, vector<int>& h) {
    h.assign(V, INF);
    h[0] = 0; // Assume a virtual node 0 connected to all other nodes with 0 weight edges

    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& e : edges) {
            if (h[e.u] != INF && h[e.u] + e.weight < h[e.v]) {
                h[e.v] = h[e.u] + e.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge& e : edges) {
        if (h[e.u] != INF && h[e.u] + e.weight < h[e.v]) {
            return false; // Negative weight cycle found
        }
    }
    return true;
}

// Dijkstra's algorithm to find the shortest path from a single source
vector<int> dijkstra(int V, const vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (const pair<int, int>& edge : adj[u]) {  // No structured bindings here
            int v = edge.first;  // Get vertex
            int weight = edge.second;  // Get weight

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void johnson(int V, vector<Edge>& edges) {
    // Add a virtual node connected to all other nodes with edges of weight 0
    vector<Edge> new_edges = edges;
    for (int i = 0; i < V; ++i) {
        new_edges.push_back({V, i, 0});
    }

    // Bellman-Ford to get the h values (reweighting function)
    vector<int> h(V + 1);
    if (!bellmanFord(V + 1, new_edges, h)) {
        cout << "Negative weight cycle detected!" << endl;
        return;
    }

    // Reweight the original graph
    vector<vector<pair<int, int>>> adj(V);
    for (const Edge& e : edges) {
        adj[e.u].emplace_back(e.v, e.weight + h[e.u] - h[e.v]);
    }

    // Apply Dijkstra's algorithm from each vertex
    for (int u = 0; u < V; ++u) {
        vector<int> dist = dijkstra(V, adj, u);
        for (int v = 0; v < V; ++v) {
            if (dist[v] != INF) {
                cout << "Shortest path from " << u << " to " << v << " is " 
                     << dist[v] - h[u] + h[v] << endl;
            } else {
                cout << "No path from " << u << " to " << v << endl;
            }
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    johnson(V, edges);

    return 0;
}
