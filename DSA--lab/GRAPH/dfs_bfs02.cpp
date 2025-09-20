//shortest path

#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>& adj, int v, int start, int destination) {
    vector<bool> vis(v + 1, false);
    vector<int> parent(v + 1, -1); // Array to store parent of each vertex
    
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto& neighbor : adj[cur]) {
            if (!vis[neighbor]) {
                q.push(neighbor);
                vis[neighbor] = true;
                parent[neighbor] = cur; // Update parent
            }
        }
    }

    // Backtrack to find the shortest path
    vector<int> path;
    for (int i = destination; i != -1; i = parent[i])
        path.push_back(i);

    if (path.back() != start) {
        cout << "No path exists from " << start << " to " << destination << "\n";
    } else {
        cout << "Shortest path from " << start << " to " << destination << ":\n";
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i];
            if (i > 0)
                cout << " -> ";
        }
        cout << "\n";
    }
}

int main() {
    int v, e;

    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj(v + 1);

    for (int i = 1; i <= e; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int start, destination;
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "Enter destination vertex: ";
    cin >> destination;

    BFS(adj, v, start, destination);
}