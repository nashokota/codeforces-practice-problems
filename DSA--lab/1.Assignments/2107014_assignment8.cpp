#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void Bouble_sort(vector<int>&arr,int n)
{
     for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }

}

void Insertion_sort(vector<int>&arr,int n)
{
     for(int i=0;i<n;i++)
   {
    int j=i;
    while(j>0 && arr[j]<arr[j-1])
    {
        swap(arr[j],arr[j-1]);
        j--;
    }
   }
}

void Selection_sort(vector<int>&arr,int n)
{
     int min=0;
    for(int i=0;i<=n-2;i++)
    {
        min=i;
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

int func(vector<int>&arr,int l, int h)
{
    int pivot = arr[l];
    int i =l+1;
    int j =h;
    while (true) 
    {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

void Quick_sort(vector<int>&arr , int low ,int high)
{
    if(low<high)
    {
        int pivot = func(arr,low,high);
        Quick_sort(arr,low,pivot-1);
        Quick_sort(arr,pivot+1,high);
    }
}

void Merge(vector<int>& arr, int l, int m, int h) {
    vector<int> tmp(h - l + 1);
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= h) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        tmp[k++] = arr[i++];
    }
    while (j <= h) {
        tmp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[l + p] = tmp[p];
    }
}

void MergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

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


void heapSort(vector<int>& arr,int n)
 {
    // int n = arr.size();

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

void Count_sort(vector<int>&arr,int n,int e)
{
    vector<int>arr1(n);
    int i, cnt[10]={0};

    for(i=0;i<n;i++)
    {
        cnt[(arr[i]/e) % 10]++;
    }
    for(i=1;i<10;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        arr1[cnt[(arr[i]/e)%10]-1]=arr[i];
        cnt[(arr[i]/e)%10]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i]=arr1[i];
    }
}

void Count_sort(vector<int>&arr,int n)
{
    int M=0;
    for(int i=0;i<n;i++)
    {
        M=max(M,arr[i]);
    }
    vector<int> cnt(M+1,0);

    vector<int>arr1(n);
    int i; 

    for(i=0;i<n;i++)
    {
      cnt[arr[i]]++;
    }
    for(i=1;i<=M;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        arr1[cnt[arr[i]]-1]=arr[i];
        cnt[arr[i]]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i]=arr1[i];
    }
}

int max_val(vector<int>&arr,int n)
{
    int max =arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
void Radix_sort(vector<int>&arr,int n)
{
    int max = max_val(arr,n);

    for(int i=1;max/i>0;i*=10)
    {
        Count_sort(arr,n,i);
    }
}

void Display(vector<int>&arr,int n)
{
    cout << "The current array is :";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main()
{
    srand(time(NULL));
     int n ;
    cout << "The array size :";
    cin>>n;

    vector<int>arr(n);

    cout << "Generating Random array... ... ..."<<endl;

    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
    Display(arr,n);
    // cout << "Input the array elements :";
    // for (int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }   

    cout << " ---Select operation--- "<<endl;
    cout << "1.Bouble Sort "<<endl;
    cout << "2.Insertion Sort "<<endl;
    cout << "3.Selection Sort "<<endl;
    cout << "4.Quick Sort "<<endl;
    cout << "5.Merge Sort "<<endl;
    cout << "6.Heap Sort "<<endl;
    cout << "7.Radix Sort "<<endl;
    cout << "8.Count Sort "<<endl;
    
    cout << " Give  Input :";
    int m;cin>>m;
    auto start = high_resolution_clock::now();
    switch (m)
    {
    case 1:
        Bouble_sort(arr,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;
    case 2:
        Insertion_sort(arr,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;
    case 3:
        Selection_sort(arr,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;
    case 4:
        Quick_sort(arr,0,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;
    case 5:
        MergeSort(arr,0,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;
    case 6:
        heapSort(arr,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;
    case 7:
        Radix_sort(arr,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;
    case 8:
        Count_sort(arr,n);
        cout << "After sorting , ";
        Display(arr,n);
        break;                        
    default:
        cout << "Invalid Selection "<<endl;
        break;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    
    return 0;
}