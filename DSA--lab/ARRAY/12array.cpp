// Merging two array in sorted//
#include <bits/stdc++.h>
using namespace std;

void merge_array(int arr1[],int arr2[],int n ,int m)
{
    int arr3[n+m];
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }   
    for(;i<n;i++)
    {
        arr3[k++]=arr1[i];
    }
    for(;j<m;j++)
    {
        arr3[k++]=arr2[j];
    }

    //printing 
    cout << "After merging "<<endl;
    for(k=0;k<(n+m);k++)
    {
        cout << arr3[k]<< " ";
    }
}

int main()
{
    int n,m;
    cout << "Input the size of 1st array and 2nd array :";
    cin>>n>>m;
 int arr1[n],arr2[m];
    cout << "input 1st array :"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>arr1[i];
    }   
    cout << "input 2nd array :"<<endl;
    for(int i =0;i<m;i++)
    {
        cin>>arr2[i];
    }   

    merge_array(arr1,arr2,n,m);
    return 0;
}

// #include <iostream>
// using namespace std;

// void merge_array(int arr1[], int arr2[], int n, int m) {
//     int *arr3 = new int[n + m];
//     int i = 0, j = 0, k = 0;
//     while (i < n && j < m) {
//         if (arr1[i] < arr2[j]) {
//             arr3[k++] = arr1[i++];
//         } else {
//             arr3[k++] = arr2[j++];
//         }
//     }
//     while (i < n) {
//         arr3[k++] = arr1[i++];
//     }
//     while (j < m) {
//         arr3[k++] = arr2[j++];
//     }

//     // Printing
//     cout << "After merging" << endl;
//     for (k = 0; k < (n + m); k++) {
//         cout << arr3[k] << " ";
//     }
//     delete[] arr3; // Freeing dynamically allocated memory
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     int *arr1 = new int[n];
//     int *arr2 = new int[m];
//     cout << "Input 1st array:" << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> arr1[i];
//     }
//     cout << "Input 2nd array:" << endl;
//     for (int i = 0; i < m; i++) {
//         cin >> arr2[i];
//     }
//     merge_array(arr1, arr2, n, m);
//     delete[] arr1; // Freeing dynamically allocated memory
//     delete[] arr2; // Freeing dynamically allocated memory
//     return 0;
// }
