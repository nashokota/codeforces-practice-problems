// time complexity for max heap creating ->O(NlogN)
// we can  delete only largest element in max heap
// can only delete highest priority element
// when root is removed the last element will take this place
// heap sort time complexity -> O(NlogN)
#include <bits/stdc++.h>
using namespace std;

int Heap_sort(int  arr[],int n)
{
      int x,i,j;
    x=arr[n];
    arr[1]=arr[n];
    i=1;j=i*2;
    while(j<n-1)
    {
        if(arr[j+1]>arr[j])
        {
            j+=1;
        }
        if(arr[i]<arr[j])
        {
            swap(arr[i],arr[j]);
            i=j;
            j*=2;
        }
        else break;
    }
    // storing the deleted element in free space
    arr[n]=x;
    return arr[n];
}

int Delete(int arr[],int n)
{
    int x,i,j,val=arr[1];
    x=arr[n];
    arr[1]=arr[n];
    i=1;j=i*2;
    while(j<n-1)
    {
        if(arr[j+1]>arr[j])
        {
            j+=1;
        }
        if(arr[i]<arr[j])
        {
            swap(arr[i],arr[j]);
            i=j;
            j*=2;
        }
        else break;
    }
    arr[n]=val;
    return val;
}

void Insert(int arr[],int n)
{
    int tmp,i=n;
    tmp=arr[n];
    while(i>1 && tmp>arr[i/2])
    {
        arr[i]=arr[i/2];
        i=i/2;
    }
    arr[i]=tmp;
}

void disp_Heap(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}



int main()
{
    int arr[8]={0,10,20,30,25,5,40,35};
     int i;
    for(i=2;i<=7;i++)
    {
        Insert(arr,i);
    }
     disp_Heap(arr,sizeof(arr)/sizeof(arr[0]));    
    // cout << "Deleted value is : "<< Delete(arr,7)<<endl;
    // cout << "After deleted the Heap is :";
    //  disp_Heap(arr,sizeof(arr)/sizeof(arr[0]));   
    //   cout << "Deleted value is : "<< Delete(arr,6)<<endl;
    // cout << "After deleted the Heap is :";
    //  disp_Heap(arr,sizeof(arr)/sizeof(arr[0]));   
   
   //heap sort
   for(int i=7;i>1;i--)
   {
    Delete(arr,i);
   }
   cout << "Heap sort :";
   disp_Heap(arr,8);
    return 0;
}