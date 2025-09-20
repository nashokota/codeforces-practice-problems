/*
#cse2202 lab3 B1
input V, E // number of vertices and edges
next E lines u, v, w // undirected graph
input source

we have to print the nodes that might potentially be negative distance from the source node
*/

#include <bits/stdc++.h>
using namespace std;

void find_negative_nodes(int start, vector<int>& dist, vector<pair<int, pair<int, int>>>& edges) {
    vector<bool> visited(dist.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    // Perform BFS from the start node to find all nodes reachable from negative cycles
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto edge : edges) {
            int v = edge.second.first;
            if (edge.first == u && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << "Nodes that might have a negative distance from the source: ";
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void bellman_ford(vector<pair<int, pair<int, int>>>& edges, int v, int src) {
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    // Relax all edges (v-1) times
    for (int i = 0; i < v - 1; i++) {
        for (auto it : edges) {
            int u = it.first;
            int v = it.second.first;
            int w = it.second.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles and identify nodes affected by them
    bool has_negative_cycle = false;
    int cycle_start = -1;
    for (auto it : edges) {
        int u = it.first;
        int v = it.second.first;
        int w = it.second.second;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            has_negative_cycle = true;
            cycle_start = v; // Mark the start of the cycle
            break;
        }
    }

    // If a negative cycle exists, identify nodes potentially affected
    if (has_negative_cycle) {
        cout << "Negative cycle detected!" << endl;
        find_negative_nodes(cycle_start, dist, edges);
    } else {
        // If no negative cycle, print the distances
        cout << "The distances from the " << src << " node are: ";
        for (int i = 0; i < v; i++) {
            if (dist[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v, e;
    cout << "Input vertices and edges: ";
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edges;
    cout << "Input the edges (u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, {v, w}});
    }
    int src;
    cout << "Input the source node: ";
    cin >> src;

    bellman_ford(edges, v, src);

    return 0;
}
