//Find 'k'th largest and smallest element of an array //
#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

int findKthSmallest(int arr[], int length, int k) {
    // Sort the array
    sort(arr, arr + length);
    // Return the k-th smallest element
    return arr[k - 1];
}

int findKthLargest(int arr[], int length, int k) {
    // Sort the array
    sort(arr, arr + length, greater<int>());
    // Return the k-th largest element
    return arr[k - 1];
}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int length = sizeof(arr) / sizeof(arr[0]);
    int k = 1; // Example: finding the 2nd smallest and largest element

    cout << "Array: ";
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << k<<"-th smallest element: " << findKthSmallest(arr, length, k) << endl;
    cout << k<<"-th largest element: " << findKthLargest(arr, length, k) << endl;

    return 0;
}
