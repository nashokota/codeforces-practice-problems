// #include <bits/stdc++.h>
// using namespace std;

// void func(int arr[], int i, int t)
// {
    
//     for(int m=0;m<t;m++)
//     {
//         if(arr[m]== i)
//         return ;
//     }
//     cout << i<<endl;
// }

// int main()
// {
   
//     int t;
//     cin>>t;
//     int arr[t-1];
//     for (int i=0;i<t-1;i++)
//     {
//         cin>>arr[i];
//     }

//     for(int i=1;i<=t;i++)
//     {
//      func(arr,i,t);
//     }
//     return 0;
// }


#include<bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  bool watched[n + 1]; 
  for (int i = 1; i <= n; i++) {
    watched[i] = false; 
  }
  for (int i = 1; i < n; i++) {
    int episode; cin >> episode;
    watched[episode] = true; 
  }
  int not_watched = -1;
  
  for (int i = 1; i <= n; i++) {
    if (!watched[i]) {
      not_watched = i;
    }
  }
  cout << not_watched << '\n';
  assert(not_watched != -1);
  
  return 0;
}
