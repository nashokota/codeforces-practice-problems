#include <bits/stdc++.h>
using namespace std;

// time complexity : nlog(n)

void Merge(vector<int>&arr , int l,int m,int h)
{
    vector<int>tmp;
    int left=l;
    int right =m+1;
    while(left<=m && right<=h)
    {
        if(arr[left]<=arr[right])
        {
            tmp.push_back(arr[left++]);
        }
        else{
            tmp.push_back(arr[right++]);
        }
    }
    while(left<=m)
    {
        tmp.push_back(arr[left++]);
    }
    while(right<=h)
    {
         tmp.push_back(arr[right++]);
    }

    for(int i=l;i<=h;i++)
    {
        arr[i]=tmp[i-l];
    }
}

void MS(vector<int>&arr , int low ,int high)
{
    if(low>=high) return;
    int mid=(low+high)/2;
    MS(arr,low,mid);
    MS(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

void mergeSort(vector<int>&arr , int n)
{
    MS(arr, 0 , n-1);
}

void disp(vector<int>&arr, int n)
{
    for(int i=0;i<n;i++)
    {
       cout << arr[i]<< " ";
    }
}

int main()
{
    vector<int>arr = {3,9,2,5,7,1,8};
    int n = arr.size();

    mergeSort(arr,n);
    disp(arr,n);
    return 0;
}