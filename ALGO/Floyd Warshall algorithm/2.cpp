#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

// Function to count intermediate nodes used in the shortest path
void update_path_count(vector<vector<int>>& parent, int i, int j, vector<int>& node_count) {
    if (i != j) {
        int intermediate = parent[i][j];
        if (intermediate != i && intermediate != j) {
            node_count[intermediate]++;  // Count the intermediate node only once per shortest path
            update_path_count(parent, i, intermediate, node_count);
            update_path_count(parent, intermediate, j, node_count);
        }
    }
}

// Floyd-Warshall algorithm to find all pairs shortest paths
void floyd_warshall(vector<vector<int>>& dist, vector<vector<int>>& parent, int v, vector<int>& node_count) {
    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = k;  // Track the intermediate node
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < v; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    // Count node usage for all shortest paths
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i != j && dist[i][j] != INF) {
                update_path_count(parent, i, j, node_count);
            }
        }
    }
}

int main() {
    int v, e;
    cout << "Input the number of vertices and edges: ";
    cin >> v >> e;

    // Initialize the distance and parent matrices
    vector<vector<int>> dist(v, vector<int>(v, INF));
    vector<vector<int>> parent(v, vector<int>(v, -1));
    vector<int> node_count(v, 0);  // Count how many times each node is used

    // Input the edges and initialize the matrices
    cout << "Input the edges (x y w):" << endl;
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = w;
        parent[x][y] = x;  // Set the parent of the destination as the source
    }

    // Initialize distance from vertex to itself as 0
    for (int i = 0; i < v; i++) {
        dist[i][i] = 0;
        parent[i][i] = i;
    }

    // Run the Floyd-Warshall algorithm
    floyd_warshall(dist, parent, v, node_count);

    // Find the most used node
    int most_used_node = -1, max_usage = 0;
    for (int i = 0; i < v; i++) {
        if (node_count[i] > max_usage) {
            most_used_node = i;
            max_usage = node_count[i];
        }
    }

    // Output the result
    if (most_used_node != -1) {
        cout << "The most used node is " << most_used_node << " with " << max_usage << " usages." << endl;
    } else {
        cout << "No node was used as an intermediate node in the shortest paths." << endl;
    }

    return 0;
}
