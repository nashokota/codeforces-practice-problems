#include <bits/stdc++.h>
using namespace std;

void solve()
{
      string s="codeforces";
    string a;
    cin>>a;
    int n=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=s[i])
        {
            n++;
        }
    }
    cout <<n<<endl;
}

int main()
{
  int t;
  cin>>t;
  while(t!=0)
  {
    solve();
    t--;
  }
    return 0;
}