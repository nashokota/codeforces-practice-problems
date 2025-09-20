// #include <bits/stdc++.h>
// using namespace std;

// void solve(vector<int>&arr,int n,int pos)
// {
//     vector<int>even;
//     vector<int>odd;
//     for(int num : arr)
//     {
//         if(num % 2 == 0)
//         {
//             even.push_back(num);
//         }
//         else {
//             odd.push_back(num);
//         }
//     }
//     sort(even.begin(),even.end());
//     sort(odd.begin(),odd.end());
//     arr.clear();
//     arr.insert(arr.end(),odd.begin(),odd.end());
//     arr.insert(arr.end(),even.begin(),even.end());

//     for(int i=0;i<n;i++)
//     {
//         if(i==pos)
//         {
//             cout << arr[i]<<endl;
//         }
//     }
// }

// int main()
// {
//     int n;cin>>n;
//     int pos;cin>>pos;
//     vector<int>arr;
//     for(int i=0;i<n;i++)
//     {
//         arr[i]=i+1;
//     }
//     solve(arr,n,pos);
//     return 0;
// }






// #include <iostream>
// #include <vector>
// #include <algorithm>

// void segregateAndSortArray(std::vector<int>& arr) {
//     // Separate odd and even numbers
//     std::vector<int> oddNumbers;
//     std::vector<int> evenNumbers;

//     for (int num : arr) {
//         if (num % 2 == 0) {
//             evenNumbers.push_back(num);
//         } else {
//             oddNumbers.push_back(num);
//         }
//     }

//     // Sort the odd and even numbers
//     std::sort(oddNumbers.begin(), oddNumbers.end());
//     std::sort(evenNumbers.begin(), evenNumbers.end());

//     // Combine the sorted odd and even numbers
//     arr.clear();
//     arr.insert(arr.end(), oddNumbers.begin(), oddNumbers.end());
//     arr.insert(arr.end(), evenNumbers.begin(), evenNumbers.end());
// }

// int main() {
//     // Example usage
//     int n;std::cin>>n;
//     int pos;std::cin>>pos;
//     std::vector<int> arr ;

//    // std::cout << "Original Array: ";
//     for (int i=0;i<n;i++) {
//         arr.push_back(i+1);
//             }

//     segregateAndSortArray(arr);

//     // std::cout << "\nModified Array: ";
//     // for (int num : arr) {
//     //     std::cout << num << " ";
//     // }

//     for(int i=0;i<n;i++)
//     {
//         if(i==pos-1)
//         {
//             std::cout <<arr[i]<<std::endl;
//         }
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long int n;cin>>n;
    long long int pos;cin>>pos;

    long long int middle = (n+1)/2;

    if(pos<=middle)
    {
        cout << pos*2-1<<endl;
    }
    else 
    {
        cout << (pos-middle)*2<<endl;
    }
    return 0;
}