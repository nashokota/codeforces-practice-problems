#include <iostream>
using namespace std;

void solve()
{
   int x;
    cin>>x;
    int ar[x];
    for(int j=0;j<x;j++)
    {
        cin >> ar[j];
    }
    
    int  fact1 = 1, i, fact2 = 1, ans;
    for (i = 1; i <= (10-x); i++)
        fact1 = fact1 * i;

        for (i = 1; i <= (8-x); i++)
        fact2 = fact2 * i;

ans= 6*fact1/(2*fact2);
cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}