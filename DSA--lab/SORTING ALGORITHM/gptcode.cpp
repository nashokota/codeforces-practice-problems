#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void Bubble_sort(vector<int>& arr, int n) {
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Insertion_sort(vector<int>& arr, int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void Selection_sort(vector<int>& arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while(true) {
        while(i <= j && arr[i] <= pivot) i++;
        while(i <= j && arr[j] > pivot) j--;
        if(i <= j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void Quick_sort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        Quick_sort(arr, low, pivot - 1);
        Quick_sort(arr, pivot + 1, high);
    }
}

void Merge(vector<int>& arr, int l, int m, int h) {
    vector<int> tmp(h - l + 1);
    int i = l, j = m + 1, k = 0;
    while(i <= m && j <= h) {
        if(arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while(i <= m) {
        tmp[k++] = arr[i++];
    }
    while(j <= h) {
        tmp[k++] = arr[j++];
    }
    for(int p = 0; p < k; p++) {
        arr[l + p] = tmp[p];
    }
}

void Merge_sort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        Merge_sort(arr, low, mid);
        Merge_sort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void Heap_sort(vector<int>& arr, int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void Count_sort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i] - min_val]++;

    for(int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for(int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    for(int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void Radix_sort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    for(int exp = 1; max_val / exp > 0; exp *= 10)
        Count_sort(arr);
}

void Display(const vector<int>& arr) {
    cout << "Sorted array: ";
    for(int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    srand(time(nullptr));

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = rand(); // Generate random numbers

    cout << "Array generated." << endl;
    Display(arr);
    cout << "Select sorting algorithm:\n"
         << "1. Bubble Sort\n"
         << "2. Insertion Sort\n"
         << "3. Selection Sort\n"
         << "4. Quick Sort\n"
         << "5. Merge Sort\n"
         << "6. Heap Sort\n"
         << "7. Radix Sort\n"
         << "8. Count Sort\n"
         << "Choice: ";

    int choice;
    cin >> choice;

    auto start = high_resolution_clock::now();
    switch(choice) {
        case 1:
            Bubble_sort(arr, n);
            break;
        case 2:
            Insertion_sort(arr, n);
            break;
        case 3:
            Selection_sort(arr, n);
            break;
        case 4:
            Quick_sort(arr, 0, n - 1);
            break;
        case 5:
            Merge_sort(arr, 0, n - 1);
            break;
        case 6:
            Heap_sort(arr, n);
            break;
        case 7:
            Radix_sort(arr);
            break;
        case 8:
            Count_sort(arr);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    Display(arr);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
