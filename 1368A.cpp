#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c, d, n;
    cin >> a >> b >> n;
    int count = 0;
    if(a>b)
    {
        while(b <= n)
        {
            b += a; count++;
            //cout <<"b = " << b << " count = " << count << endl;
            swap(a, b);
        }
        cout << count-1 << endl;
    }
    else
    {
        while(a <= n)
        {
            a += b; count++;
            //cout <<"b = " << b << " count = " << count << endl;
            swap(a, b);
        }
        cout << count-1 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}












// // #include <bits/stdc++.h>
// // using namespace std;


// // int main()
// // {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(0);
// //     cout.tie(0);
// //     int m=0;
// //     int a,b,i,n,count=0,countt=0;
// //     cin>>i;
// //    while (i)
// //     {count=0,countt=0;
// //     cin>>a>>b>>n;

// //     if(a>b)
// //     {
// //         for(;a<n;){
// //         a+=b;
// //         count++;}
// //     // if(a>n){cout << count; }

// //     }
// //     if(a<b)
// //     {
// //         for(;b<n;)
// //         {
// //             b+=a;
// //         count++;
// //         }
// //     //if(b>n){cout << count; }

// //     }
// //     i--;
// //     }
// //     cout << count << endl;
// //     cout << count ;
    
// //     return 0;
// // }





// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     int a,b,n,count=0;
//     cin>>a>>b>>n;

//     if(a>b)
//     {
//         for(;a<=n;){
//         a+=b;
//         count++;}

//     }
//     if(a<b)
//     {
//         for(;b<=n;)
//         {
//             b+=a;
//         count++;
//         }
//     }
//         cout << count ;
//     return 0;
// }