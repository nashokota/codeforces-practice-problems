// Dijkstra's algorithm using SET

#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adj, int v, int src) {
    set<pair<int, int>> st;  
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for (auto it : adj[node]) {
            int adj_node = it.first;
            int edge_weight = it.second;

            if (dist[adj_node] > dis + edge_weight) {
                if (dist[adj_node] != INT_MAX) {
                    st.erase({dist[adj_node], adj_node});
                }
                dist[adj_node] = dis + edge_weight;
                st.insert({dist[adj_node], adj_node});
            }
        }
    }

    cout << "Output distance: ";
    for (int i = 0; i < v; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int v, e;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;
    cout << "Enter the edges and weight (x y w):" << endl;

    vector<vector<pair<int, int>>> adj(v);
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});  
    }

    cout << "Enter source node: ";
    int src;
    cin >> src;

    dijkstra(adj, v, src);

    return 0;
}
