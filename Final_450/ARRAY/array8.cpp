// Given an array Arr[] of N integers. 
// Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
// Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[],int n)
{
    long long int ans =arr[0];
    for(int i=0;i<n;i++)
    {
        long long int tmp=0;
        for(int j=i;j<n;j++)
        {
            tmp+=arr[j];
            ans= max(ans,tmp);
        }
    }
    return ans;
}

int main()
{
    int n;cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];

    cout << "OUTPUT : "<< maxSubarraySum(ar,n)<<endl;
    return 0;
}