// Delete array element //
#include <bits/stdc++.h>
using namespace std;

int deleteElement(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            break;
    }

    // If key is not present in array
    if (i == n)
        return n;

    // Move elements after key one position back
    for (int j = i; j < n - 1; j++)
        arr[j] = arr[j + 1];

    return (n - 1); // Decrement the size of the array
}

int main()
{
     int i;
    int arr[] = { 10, 50, 30, 40, 20 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
 
    cout << "Array before deletion\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    // Function call
    n = deleteElement(arr, n, key);
 
    cout << "\n\nArray after deletion\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}