#include <bits/stdc++.h>
using namespace std;

void solve()
{
      vector<int> letter;
    for (int i = 0; i < 26; ++i) {
        letter.push_back(0);
    }
    int n, f, i;
    queue<int> q;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> f;
        q.push(f);
    }
    while(!q.empty()) {
    for (i = 0; letter[i] != q.front(); ++i);
    cout << (char)(i+97);
    q.pop();
    letter[i]++;
    }
    cout<<endl;
}

int main()
{
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
    return 0;
}