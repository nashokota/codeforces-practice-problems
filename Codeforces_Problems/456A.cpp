// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     int n;cin>>n;
//     int arr[100][100];

//     for(int i=0;i<n;i++)
//     {
//        cin<<arr[i][0]<<arr[i][1];
//     }

//     for(int i=0;i<n;i++)
//     {
//         if(arr[i][0]<arr[i+1][0] && arr[i][1]>arr[i+1][1])
//         {
//             cout <<"Happy Alex";
//             return 0;
//         }
       
//     }
//     cout << "Poor Alex";
//     return 0;
// }


// #include <iostream>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
    
//     pair<int, int> arr[100];

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i].first >> arr[i].second;
//     }

//     sort(arr, arr + n);

//     for (int i = 0; i < n - 1; i++) {
//         if (arr[i].second > arr[i + 1].second) {
//             cout << "Happy Alex";
//             return 0;
//         }
//     }

//     cout << "Poor Alex";
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;



int main()
{
 int n;cin>>n;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    if(a!=b)
    {
      cout << "Happy Alex";
             return 0;
    }
  }   
  cout << "Poor Alex";
    return 0;
}