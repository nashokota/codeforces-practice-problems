//Reverse an array //
#include <bits/stdc++.h>
using namespace std;

void arr_traverse(int *arr,int n)
{
    
    for(int i=0;i<n;i++)
    {
        cout << arr[i]<< " ";
    }
    cout <<endl;
}

void arr_reverse(int *arr,int k)
{
    int i,j;
    //k=sizeof(arr)/sizeof(arr[0]);
    for(i=0,j=k-1;i<j;i++,j--)
    {
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
}

int main()
{
 int arr[]={8,3,9,15,6,7,2,12,4};
 int n= sizeof(arr)/sizeof(arr[0]);
 
 cout << "before shifting "<<endl;
 arr_traverse( arr,n);
 arr_reverse(arr,n);
 
 cout << "After Reversing "<<endl;
arr_traverse(arr,n);
    return 0;
}