//lower bound ...upper bound//
#include <bits/stdc++.h>
using namespace std;

int Bsearch_lower(int arr[],int key,int n)
{
   int l=0;
   int h=n-1;
   int mid;
   while (l<=h)
   {
    mid=(l+h)/2;
    if(arr[mid]==key)
    {
        return mid+1;
    }
    else if(arr[mid]>key)
    {
        h=mid-1;
    }
    else{
        l=mid+1;
    }
   }
}

int Bsearch_upper(int arr[],int key,int n)
{
   int l=0;
   int h=n-1;
   int mid;
   while (l<=h)
   {
    mid=(l+h)/2;
    if(arr[mid]==key)
    {
        return mid-1;
    }
    else if(arr[mid]>key)
    {
        h=mid-1;
    }
    else{
        l=mid+1;
    }
   }
}
int main()
{
    int arr[20]={2,5,7,9,10,17,23,26,55,64,69};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout << "Enter Value :"<<endl;
    cin>>key;

    int j= Bsearch_lower(arr,key,n);
        cout << " the lower bound is : "<<arr[j]<<endl;

    int k= Bsearch_upper(arr,key,n);
        cout << " the upper bound is : "<<arr[k]<<endl;
       return 0;
}