//  '-'ve element swap to left side //
#include <bits/stdc++.h>
using namespace std;

void neg_ele_shift(int arr[],int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while (arr[i]<0)
        {
            i++;
        }
        while(arr[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
}
void arr_traverse(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout << arr[i]<< " ";
    cout <<endl;
}
int main()
{
 int arr[]={-6,3,-8,10,5,-7,-9,12,-4,2};
 int n=sizeof(arr)/sizeof(arr[0]);
cout << "before shift :"<<endl;
arr_traverse(arr,n);
cout << "After shifting :" <<endl;
 neg_ele_shift(arr,n);
arr_traverse(arr,n);
}