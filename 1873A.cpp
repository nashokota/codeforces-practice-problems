#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string s1;
  cin>>s1;
   if (s1[0]=='a'||s1[1]=='b'||s1[2]=='c')
   {
    cout << "YES\n";
   }
   else
   {
    cout << "NO\n";
   }

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