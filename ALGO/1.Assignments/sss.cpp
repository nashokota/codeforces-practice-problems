#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <unordered_map>
#include <utility>
#include <algorithm> // for std::swap

class MinHeap {
private:
    std::vector<std::pair<int, int>> heap; // pair of (key, value)
    std::unordered_map<int, int> keyIndex; // maps key to its index in heap

    void heapifyUp(int idx) {
        if (idx == 0) return;
        int parentIdx = (idx - 1) / 2;
        if (heap[idx].second < heap[parentIdx].second) {
            std::swap(heap[idx], heap[parentIdx]);
            keyIndex[heap[idx].first] = idx;
            keyIndex[heap[parentIdx].first] = parentIdx;
            heapifyUp(parentIdx);
        }
    }

    void heapifyDown(int idx) {
        int leftIdx = 2 * idx + 1;
        int rightIdx = 2 * idx + 2;
        int smallestIdx = idx;

        if (leftIdx < heap.size() && heap[leftIdx].second < heap[smallestIdx].second) {
            smallestIdx = leftIdx;
        }

        if (rightIdx < heap.size() && heap[rightIdx].second < heap[smallestIdx].second) {
            smallestIdx = rightIdx;
        }

        if (smallestIdx != idx) {
            std::swap(heap[idx], heap[smallestIdx]);
            keyIndex[heap[idx].first] = idx;
            keyIndex[heap[smallestIdx].first] = smallestIdx;
            heapifyDown(smallestIdx);
        }
    }

public:
    void insert(int key, int value) {
        heap.push_back({key, value});
        int idx = heap.size() - 1;
        keyIndex[key] = idx;
        heapifyUp(idx);
    }

    std::pair<int, int> extract_min() {
        std::pair<int, int> minElem = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        keyIndex.erase(minElem.first);
        if (!heap.empty()) {
            keyIndex[heap[0].first] = 0;
            heapifyDown(0);
        }
        return minElem;
    }

    void decrease_key(int key, int newValue) {
        int idx = keyIndex[key];
        heap[idx].second = newValue;
        heapifyUp(idx);
    }

    bool is_empty() {
        return heap.empty();
    }
};

void dijkstra(int V, const std::vector<std::list<std::pair<int, int>>>& adj, int src) {
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    MinHeap minHeap;
    
    dist[src] = 0;
    for (int i = 0; i < V; ++i) {
        minHeap.insert(i, dist[i]);
    }

    while (!minHeap.is_empty()) {
        std::pair<int, int> minElem = minHeap.extract_min();
        int u = minElem.first;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                minHeap.decrease_key(v, dist[v]);
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << " distance from source " << src << " is " << dist[i] << std::endl;
    }
}

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::list<std::pair<int, int>>> adj(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source;
    std::cin >> source;

    dijkstra(V, adj, source);

    return 0;
}
