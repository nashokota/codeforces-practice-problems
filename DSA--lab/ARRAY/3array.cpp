//Insert at any position by array index
#include <bits/stdc++.h>
using namespace std;

void InsertElement(int arr[] , int n , int k ,int pos)
{
    for (int i=n-1; i >=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos] = k;
}

int main()
{
    int arr[15]={1,2,3,4,5,7,9};
    int n=7;
    int x=55 ,pos=3;
    cout <<"\nBefore Insertion :";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;

    InsertElement(arr, n, x ,pos);
    n++;
     cout << "After insertion : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}