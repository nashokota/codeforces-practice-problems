#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    string ss1,ss2;
    cin>>ss1>>ss2;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+= min(abs(ss1[i]-ss2[i]),10-abs(ss1[i]-ss2[i]));
    }
    cout << cnt;
    return 0;
}