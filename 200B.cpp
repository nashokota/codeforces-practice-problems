#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;cin>>t;
    int ar[t];
        long double ans=0;
    for(int i=0;i<t;i++)
    {
        cin>>ar[i];
        ans+= (long double)ar[i]/100;
       // cout << ans<<endl;
    }

    ans=(ans/t)*100;

    cout << setprecision(12)<<ans<<endl;


    return 0;
}