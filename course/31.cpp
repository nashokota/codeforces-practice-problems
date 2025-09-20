// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     int n = 78;

//     cout << n <<" in binary is :"<< bitset<32>(n)<<endl;
// // even bits swap......................//odd bit swap
//     n = (( n& 0xAAAAAAAA ) >>1) | ((n& 0x55555555 )<<1) ;

//     cout << n <<" in binary is :"<< bitset<32>(n)<<endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    n= (((n& 0xAAAAAAAA)>>1) | ((n& 0x55555555)<<1));
    cout << n <<" ";
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