// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     int n;cin>>n;
//     long long int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
// int ans = INT_MAX;
// int ans2=0;
//     for(int i=0;i<n;i++)
//     {
//         ans = min(ans,arr[i]);
//         if(ans==arr[i])
//         {
//             ans2=i+1;
//         }
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]==arr[j])
//             {
//                 cout << "Still Rozdil"<<endl;
//                 return 0;
//             }
//         }
//     }
//     cout << ans2 <<endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;



int main()
{
     int n;
     cin>>n;
     int a[n];
     map<int,int>m;
     map<int,int>m1;
     for(int i=0;i<n;i++)
     {
       cin>>a[i];
       m[a[i]]++;
       m1[a[i]]=i+1;
     }
     for(auto e:m)
     {
       if(e.second>1){
       cout<<"Still Rozdil"<<endl;
       return 0;
       }
       else
       cout<<m1[e.first]<<endl;
       break;
     }
    return 0;
}