#include <bits/stdc++.h>
using namespace std;


long long int a[200005];
 
int main() {
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n, greater<int>());
    for(int i=1; i<=n; i++) a[i] += a[i-1];
 
    while(q--) {
        int x, y;
        cin >> x >> y;
 
        cout << a[x] - a[x-y] << endl;
    }
    return 0;
}