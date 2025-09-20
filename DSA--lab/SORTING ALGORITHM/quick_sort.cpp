#include <bits/stdc++.h>
using namespace std;

// time complexity : nlog(n)

int func(vector<int>&arr,int l, int h)
{
    int pivot = arr[l];
    int i =l;
    int j =h;
    while(i<j)
    {
        while(arr[i]<=pivot && i <= h)
        {
            i++;
        }
        while(arr[j]>=pivot && j>=l)
        {
            j--;
        }
        if(i<j)swap(arr[i],arr[j]);
    }

    swap(arr[l],arr[j]);
    return j;
}

void Qsort(vector<int>&arr , int low ,int high)
{
    if(low<high)
    {
        int pivot = func(arr,low,high);
        Qsort(arr,low,pivot-1);
        Qsort(arr,pivot+1,high);
    }
}

int main()
{
    vector<int> arr ={2,5,7,11,9,1,33,8};
    int n=arr.size();

    Qsort(arr,0,n-1);
  
for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }  
    return 0;
}