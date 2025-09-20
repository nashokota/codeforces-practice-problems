#include<bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for (; t--;) {
		int n, m;
		string s, x;
		cin >> n >> m >> x >> s;
		int ans = 0;
		for (; x.find(s) == x.npos && x.size() <= n * m; ++ans)
			x += x;
		if (x.find(s) == x.npos)
			ans = -1;
		cout << ans << '\n';
	}
}