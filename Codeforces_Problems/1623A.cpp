#include <bits/stdc++.h>
using namespace std;
int ans;
int n, m, rb, cb, rd, cd;
int dr, dc;

void moveRobot() {
	if (rb == rd || cb == cd)
		return;

	++ans;

	if (rb + dr > n || rb + dr < 1)
		dr *= -1;

	if (cb + dc > m || cb + dc < 1)
		dc *= -1;

	rb += dr;
	cb += dc;

	moveRobot();
}

void solve() {
	cin >> n >> m >> rb >> cb >> rd >> cd;

	if (rb == rd || cb == cd) {
		cout << 0;
		return;
	}

	ans = 0;
	dr = dc = 1;

	moveRobot();

	cout << ans;
}

int main()
{
    int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}
    return 0;
}
