// Inssert Sorted
#include <bits/stdc++.h>
using namespace std;

int insertSorted(int arr[],int n,int key,int cap)
{
    if(n>=cap)
    return n;
    int i=n-1;
    while(i>=0&& arr[i]>key)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=key;
    return (n+1);
}

int main()
{
    int arr[20]={12,24,26,40,50,70};
    int cap= sizeof(arr)/sizeof(arr[0]);

    int n=6;
    int i,key=39;
    cout << "\n Before Insertion : ";
    for(i=0;i<n;i++)
    {
        cout << arr[i]<<" ";
    }
    n= insertSorted(arr,n,key,cap);
    cout << "\n After Insertion : ";
    for(i=0;i<n;i++)
    cout << arr[i]<<" ";
    return 0;
}