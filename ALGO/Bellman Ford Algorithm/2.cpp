#include <bits/stdc++.h>
using namespace std;

void print_cycle(int start, vector<int>& parent) {
    int current = start;
    vector<int> cycle;
    cycle.push_back(current);

    // Rebuild the cycle by tracing the parent nodes
    while (true) {
        current = parent[current];
        cycle.push_back(current);
        if (current == start && cycle.size() > 1) break;
    }

    reverse(cycle.begin(), cycle.end());
    cout << "Negative weighted cycle: ";
    for (auto node : cycle) {
        cout << node << " ";
    }
    cout << endl;
}

void bellman(vector<pair<int, pair<int, int>>>& edge, int v, int src) {
    vector<int> dist(v, INT_MAX);
    vector<int> parent(v, -1);
    dist[src] = 0;

    // Relax all edges (v-1) times
    for (int i = 0; i < v - 1; i++) {
        for (auto it : edge) {
            int u = it.first;
            int v = it.second.first;
            int w = it.second.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycles
    int start = -1;
    for (auto it : edge) {
        int u = it.first;
        int v = it.second.first;
        int w = it.second.second;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "There is a negative cycle!!" << endl;
            start = v; // Mark the start of the cycle
            break;
        }
    }

    // If we found a negative cycle
    if (start != -1) {
        // To ensure we reach a node in the cycle, we follow the parent chain `v` times
        for (int i = 0; i < v; i++) {
            start = parent[start];
        }

        // Print the cycle
        print_cycle(start, parent);
    } else {
        // If no negative cycle, print distances
        cout << "The distances from the " << src << " node are: ";
        for (auto d : dist) {
            if (d == INT_MAX)
                cout << "INF ";
            else
                cout << d << " ";
        }
        cout << endl;
    }
}

int main() {
    int v, e;
    cout << "Input vertices and edges: ";
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edge;
    cout << "Input the edges (x y w):" << endl;
    for (int i = 0; i < e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge.push_back({x, {y, z}});
    }
    int src;
    cout << "Input the source node: ";
    cin >> src;
    bellman(edge, v, src);
    return 0;
}
