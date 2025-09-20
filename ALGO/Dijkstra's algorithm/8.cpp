//min Multiplication to reach end
#include <bits/stdc++.h>

using namespace std;

int func(vector<int>& arr, int st, int end) {
    queue<pair<int, int>> q;
    vector<int> dist(100000, INT_MAX); // Corrected size to 100000 for mod values
    q.push({st, 0});
    dist[st] = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr) {
            int num = (it * node) % 100000;
            if (steps + 1 < dist[num]) {
                dist[num] = steps + 1;
                if (num == end) {
                    return steps + 1; // Found the shortest path
                }
                q.push({num, steps + 1});
            }
        }
    }
    
    return -1; // Return -1 if the destination is unreachable
}

int main() {
    int st, end;
    cout << "Input starting and ending number:" << endl;
    cin >> st >> end;
    vector<int> arr = {3, 4, 65}; // Directly initializing the vector
    
    int res = func(arr, st, end);
    cout << "Output: " << res << endl;
    
    return 0;
}
