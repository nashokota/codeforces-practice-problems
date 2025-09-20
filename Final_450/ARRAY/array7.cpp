// Rotate the array 'k' times clockwise //
#include <bits/stdc++.h>
using namespace std;

void Rotate(int arr[], int n, int k) {
    // Rotate the array 'k' times
    for (int i = 0; i < k; i++) {
        int lastElement = arr[n - 1]; // Store the last element
        // Shift each element to the right by one position
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = lastElement; // Move the last element to the beginning
    }
    cout <<"After rotation : ";
    for(int i=0;i<n;i++)cout << arr[i]<<" ";
}


int main()
{
    int n;cout << "Array size :";cin>>n;
    int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
    cout << "Which value you want to rotate ";int k;cin>>k;
    Rotate(arr,n,k);
    return 0;
}