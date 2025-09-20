#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> adj(v + 1);
    cout << "Enter the edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Adding this line if the graph is undirected
    }
    cout << "Enter the node you want to find the degree of: ";
    int node;
    cin >> node;

    if (node >= 1 && node <= v) {
        cout << "The degree of the node is: " << adj[node].size() << endl;
    } else {
        cout << "Invalid node entered!" << endl;
    }

    return 0;
}
