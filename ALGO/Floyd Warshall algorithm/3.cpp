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

// Function to count the usage of edges in shortest paths
void count_edges_usage(vector<vector<int>>& parent, int i, int j, vector<vector<int>>& edge_count) {
    // Build the path by moving from destination to source
    while (i != j) {
        int parent_vertex = parent[i][j]; // Get the parent of j
        if (parent_vertex != -1) {
            edge_count[parent_vertex][j]++; // Increment the edge usage count
            j = parent_vertex; // Move to the parent of the current vertex
        } else {
            break; // No more parents
        }
    }
}

// Floyd-Warshall algorithm to find all pairs shortest paths
void floyd_warshall(vector<vector<int>>& dist, vector<vector<int>>& parent, vector<vector<int>>& edge_count, int v) {
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

    // Print the shortest path from each vertex to every other vertex and count edge usage
    cout << "Shortest paths between every pair of vertices:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i != j && dist[i][j] != INF) {
                cout << "Shortest path from " << i << " to " << j << ": ";
                print_path(parent, i, j);
                cout << " with total cost = " << dist[i][j] << endl;
                
                // Count edges used in this path
                count_edges_usage(parent, i, j, edge_count);
            }
        }
    }
}

// Function to find the most used edge
tuple<int, int, int> find_most_used_edge(vector<vector<int>>& edge_count) {
    int max_count = 0;
    int most_used_edge_start = -1;
    int most_used_edge_end = -1;

    for (int i = 0; i < edge_count.size(); i++) {
        for (int j = 0; j < edge_count[i].size(); j++) {
            if (edge_count[i][j] > max_count) {
                max_count = edge_count[i][j];
                most_used_edge_start = i;
                most_used_edge_end = j;
            }
        }
    }

    return make_tuple(most_used_edge_start, most_used_edge_end, max_count);
}

int main() {
    int v, e;
    cout << "Input the number of vertices and edges: ";
    cin >> v >> e;

    // Initialize the distance, parent matrix, and edge count matrix
    vector<vector<int>> dist(v, vector<int>(v, INF));
    vector<vector<int>> parent(v, vector<int>(v));
    vector<vector<int>> edge_count(v, vector<int>(v, 0)); // To count edge usages

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
    floyd_warshall(dist, parent, edge_count, v);

    // Find and print the most used edge
    tuple<int, int, int> most_used_edge = find_most_used_edge(edge_count);
    int start = get<0>(most_used_edge);
    int end = get<1>(most_used_edge);
    int count = get<2>(most_used_edge);

    if (count > 0) {
        cout << "The most used edge is from " << start << " to " << end << " with " << count << " usages." << endl;
    } else {
        cout << "No edges were used in any shortest paths." << endl;
    }

    return 0;
}
