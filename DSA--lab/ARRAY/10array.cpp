// Insert in a sorted array //
#include <bits/stdc++.h>
using namespace std;

void arr_traverse(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout << arr[i]<< " ";
    cout <<endl;
}
void arr_insert(int arr[],int n,int key)
{
    
   int i=n-1;
    while(arr[i]>key)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=key;
    arr_traverse(arr,n+1);
}
int main()
{
    int n;
    cout << "Array size :"<<endl;
    cin>>n;
    int arr [n];
    cout << "Input your array :"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
cout <<endl;
arr_traverse(arr,n);
 cout << "Which you want to insert ? ";
 int key;
 cin>>key;
   arr_insert(arr,n,key);



    return 0;
}