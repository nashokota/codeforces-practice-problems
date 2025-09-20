#include <iostream>
using namespace std;

int find_max(int A[], int length) {
    int x = A[0]; // Initialize x to the first element of the array
    for (int i = 1; i < length; i++) {
        if (x < A[i]) {
            x = A[i];
        }
    }
    return x;
}

int find_min(int A[], int length) {
    int x = A[0]; // Initialize x to the first element of the array
    for (int i = 1; i < length; i++) {
        if (x > A[i]) {
            x = A[i];
        }
    }
    return x;
}

int main() {
    int arr[7] = {21, 45, 33, 39, 17, 6, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "MAX: " << find_max(arr, length) << endl;
    cout << "MIN: " << find_min(arr, length) << endl;
    return 0;
}
