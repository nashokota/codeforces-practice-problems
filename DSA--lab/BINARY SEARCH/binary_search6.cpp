// floor and ceil//
#include <bits/stdc++.h>
using namespace std;

int Bs_floor(int arr[],int k,int n)
{
    int ans=-1;
    int l=0;
    int h=n-1;
    int m;
    while (l<=h)
    {
        m=(l+h)/2;
        if(arr[m]<=k)
        {
            ans=arr[m];
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return ans;
}

int Bs_ceil(int arr[],int k, int n)
{
    int l=0,h=n-1,m;
    int ans=-1;
    while (l<=h)
    {
        m=(l+h)/2;
        if(arr[m]>=k)
        {
            ans=arr[m];
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}

int main()
{
    int arr[]={3,5,8,12,16,19,25,31,37,42};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    int floor= Bs_floor(arr,k,n);
    cout << "The floor is : "<<floor<<endl;
    int ceil = Bs_ceil(arr,k,n);
    cout << "The ceil is : "<<ceil<<endl;

    return 0;
}