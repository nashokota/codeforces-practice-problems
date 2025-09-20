// Search in Rotated Sorted Array and pivot 

#include <bits/stdc++.h>
using namespace std;

int Bsearch(int arr[], int l ,int h, int key )
{
   if(l>h)return -1;

   int mid =(l+h)/2;

   if(key==arr[mid]) return mid;

   else if(arr[mid]>key) return Bsearch(arr,l,mid-1,key);
   else return Bsearch(arr,mid+1,h,key); 
}

int findPivot(int arr[],int low , int high)
{
    if(low>high) return -1;
    if(low == high) return low;

    int mid = (low+high)/2;

    if(mid<high && arr[mid]>arr[mid+1])
    return mid;

    if(low<mid && arr[mid]<arr[mid-1])
    return mid-1;

    if(arr[low]<=arr[mid])
    {
        return findPivot(arr,mid+1,high);
    }
    else 
    {
        return findPivot(arr,low,mid-1);
    }
}

int Pivoted_Bsearch( int arr[], int n , int key)
{
    int pivot = findPivot(arr,0,n-1);

    if(pivot ==-1)
    {
       return  Bsearch(arr,0,n-1,key);
    }

    if(arr[pivot]==key)
    {
        return pivot;
    }

    if(arr[0]<=arr[pivot])
    {
        return Bsearch(arr,pivot+1,n-1,key);
    }
    else {
        return Bsearch(arr,0,pivot-1,key);
    }
}


int main()
{
 int arr[] = {4,5,6,7,0,1,2};
 int n =sizeof(arr)/sizeof(arr[0]);
     int key = 3;

     int ans= Pivoted_Bsearch(arr,n,key);

     cout << ans<<endl;
 
    return 0;
}