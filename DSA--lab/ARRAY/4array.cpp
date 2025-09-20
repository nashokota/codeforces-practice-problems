//Insert sorted 2
#include <bits/stdc++.h>
using namespace std;

int insertfunc(int arr[], int n,int x,int cap)
{
    if(n>=cap)
    return n;
int i;
    for(i=n-1;(i>=0 && arr[i]>x);i--)
    {
        arr[i+1]=arr[i];
    }

    arr[i+1]=x;
    return (n+1);
}

int main()
{
    int arr[20]={23,26,35,34,39,42,45,49,56,59,63};
    int n=11;
    cout <<"\n Before insertion :";
    for(int i=0;i<n;i++)
    {
        cout << arr[i]<<" ";
    }
    int x=40;
    int cap=sizeof(arr)/sizeof(arr[0]);
    n = insertfunc(arr,n,x,cap);

    cout << "\n After insertion :";
    for(int i=0;i<n;i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}