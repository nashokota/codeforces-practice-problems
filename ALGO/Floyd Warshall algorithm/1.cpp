#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

// Function to print the shortest path matrix
void print_matrix(vector<vector<int>>& dist, int v) {
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to print the shortest path in the format "i->j->k"
void print_path(vector<vector<int>>& parent, int i, int j) {
    vector<int> path;

    // Build the path recursively by moving from destination to source
    while (i != j) {
        path.push_back(j); // Add the current vertex j
        j = parent[i][j];  // Move to the parent of the current vertex
    }
    path.push_back(i);  // Add the source vertex i

    // Now print the path in "i->...->j" format
    reverse(path.begin(), path.end());  // Reverse the path to print from i to j
    for (int k = 0; k < path.size(); k++) {
        cout << path[k];
        if (k != path.size() - 1) cout << "->";  // Add "->" between vertices
    }
}

// Floyd-Warshall algorithm to find all pairs shortest paths
void floyd_warshall(vector<vector<int>>& dist, vector<vector<int>>& parent, int v) {
    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];  // Correct parent update
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

    // Print the shortest distance matrix
    print_matrix(dist, v);

    // Print the shortest path from each vertex to every other vertex
    cout << "Shortest paths between every pair of vertices:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i != j && dist[i][j] != INF) {
                cout << "Shortest path from " << i << " to " << j << ": ";
                print_path(parent, i, j);
                cout << " with total cost = " << dist[i][j] << endl;
            }
        }
    }
}

int main() {
    int v, e;
    cout << "Input the number of vertices and edges: ";
    cin >> v >> e;

    // Initialize the distance and parent matrix
    vector<vector<int>> dist(v, vector<int>(v, INF));
    vector<vector<int>> parent(v, vector<int>(v));

    // Input the edges and initialize the matrices
    cout << "Input the edges (x y w):" << endl;
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = w;
        parent[x][y] = x;  // Parent of the destination is the source
    }

    // Initialize distance from vertex to itself as 0 and set self-parents
    for (int i = 0; i < v; i++) {
        dist[i][i] = 0;
        parent[i][i] = i;
    }

    // Run the Floyd-Warshall algorithm
    floyd_warshall(dist, parent, v);

    return 0;
}
