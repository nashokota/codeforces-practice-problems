#include <bits/stdc++.h>

using namespace std;


void heapify(vector<int>& arr, int n, int i)
 {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    // If left is larger than root
    if (left < n  &&  arr[left] > arr[largest])
        largest = left;

    // If right is larger 
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // calling heapify 
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>& arr)
 {
    int n = arr.size();

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    
    //extract element 
    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
