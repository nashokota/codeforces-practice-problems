// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int v=0,p=0;
//     int i,j;
//     int t;cin>>t;
//     int arr2[t];
//     for(i=0;i<t;i++)
//     {
//         cin>>arr2[i];
//     }

//     for(i=0,j=0;i<n && j<t;)
//     {
//         if(arr[i]==arr2[j])
//         {
//             v++;
//             j++;
//             i=0;
//         }
//         else{
//             v++;
//             i++;
//         }
//     }
//     for(i=n-1,j=0;i>=0 && j<t;)
//     {
//         if(arr[i]==arr2[j])
//         {
//             p++;
//             j++;
//             i=n-1;
//         }
//         else {
//             p++;
//             i--;
//         }
//     }
//     cout << v <<" "<<p<<endl;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n, a, m, b, i, V=0, P=0;

    cin >> n;
    ll arr[n+1];
    for(i=0; i<n; i++)
    {
        cin >> a;
        arr[a] = i;
    }

    cin >> m;
    for(i=0; i<m; i++)
    {
        cin >> b;
        V += arr[b] + 1;
        P += n - arr[b];
    }

    cout << V << " " << P << endl;
    return 0;
}