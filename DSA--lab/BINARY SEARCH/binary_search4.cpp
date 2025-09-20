// count occurrence //
#include <bits/stdc++.h>
using namespace std;

int first_BSearch(int arr[],int n,int key)
{
    int l=0,h=n-1;
    int fst=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==key)
        {
            fst=mid;
            h=mid-1;
        }
        else if(arr[mid]<key)
        {
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return fst;
}

int last_BSearch(int arr[],int n,int key)
{
    int l=0,h=n-1;
    int lst=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==key)
        {
            lst=mid;
            l=mid+1;
        }
        else if(arr[mid]>key)
        {
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return lst;
}

int main()
{
    int arr[]={2,4,6,8,8,8,11,11,13};
    int n=sizeof(arr)/sizeof(arr[0]);
    int first,last;
    int key;
    cout << "input key value :";
    cin>>key;
  first= first_BSearch(arr,n,key);
    

  last=last_BSearch(arr,n,key);   
   cout << "Occurrence found :"<<last-first+1<<" times ";
    return 0;
}