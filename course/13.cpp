#include <bits/stdc++.h>
using namespace std;

void solve()
{
     int n; cin >> n;
    long long S = (long long) (n + 1) * n / 2; 
    long long sum = 0;
    for (int i = 1; i <= n; i *= 2) { 
      sum += i;
    }
    long long P = S - 2 * sum;
    cout << P << '\n';
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    solve();
   }
    return 0;
}