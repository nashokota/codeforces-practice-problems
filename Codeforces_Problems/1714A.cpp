#include <bits/stdc++.h>
using namespace std;

void solve_it() {
    int n;
    cin >> n; // Added input for 'n'
    int h1, m1;
    vector<pair<int,int>> vec(n + 1); // Corrected vector initialization size
    int x, y;
    cin >> x >> y;
    vec[0] = {x, y}; // Fixed vector element insertion
    int min1 = x * 60 + y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        vec[i] = {x, y}; // Fixed vector element insertion
    }
    int H = INT_MAX;
    int M = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int min2 = vec[i].first * 60 + vec[i].second;
        int ans = min2 - min1;
        if (ans < 0) {
            ans = 24 * 60 + ans; // Fixed calculation for negative time difference
        }
        h1 = ans / 60;
        m1 = ans % 60;
        if (h1 < H || (h1 == H && m1 < M)) { // Corrected condition for updating H and M
            H = h1;
            M = m1;
        }
    }
    cout << H << " " << M << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve_it();
    }   
    return 0;
}
