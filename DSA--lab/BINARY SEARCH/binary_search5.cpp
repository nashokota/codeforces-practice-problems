// insert if not there //
#include <bits/stdc++.h>
using namespace std;

int BSearch(int arr[],int n,int key)
{
    int l=0;
   int h=n-1;
   int mid;
   int ans =n;
   if(key>20)
   {return n;}
   while (l<=h)
   {
    mid=(l+h)/2;
    if(arr[mid]==key)
    {
        return mid;
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
    int arr[]={2,4,6,8,10,12,14,16,18,20};
    int n= sizeof(arr)/ sizeof(arr[1]);
    cout <<n;
    int key;
    cout << "Give your value "<< endl;
    cin>>key;
    cout <<endl;
   cout << BSearch(arr,n,key);
    return 0;
}