#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;cin>>t;
    int ar[2];
    int ans=0;
    int c=0;
    while(t--){
        for(int i=0;i<2;i++)
        {
            cin>>ar[i];
        }
        ans=ans-ar[0];
        ans=ans+ar[1];
        c=max(c,ans);
    }
    cout << c <<endl;
    return 0;
}