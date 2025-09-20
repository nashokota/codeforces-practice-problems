#include <bits/stdc++.h>
using namespace std;

int Bsearch(int arr[],int low , int high , int key)
{


    if(low>high){return -1;}


    int mid;
    mid=(low+high)/2;
    if(key==arr[mid])
    {
        return mid ;
    }
    else if (key>arr[mid])
    {
        return Bsearch(arr,mid+1,high,key);
    }
    else
    {
        return Bsearch(arr,low,mid-1,key);
    }
}

int main()
{
    int arr[20]={2,5,7,23,33,44,55};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout << "Enter Value :"<<endl;
    cin>>key;

    n= Bsearch(arr, 0, 8 , key);

    if(n==-1)
    {
        cout << " NOT FOUND "<<endl;
    }   
    else 
    {
        cout << "VALUE FOUND AT INDEX :"<< n <<endl;
    }
    return 0;
}