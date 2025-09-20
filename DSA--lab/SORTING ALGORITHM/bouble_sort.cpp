#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cout << "Give array size :"<<endl;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //bouble sort
/*
    swap adjacent till next and every time will escape the last
*/
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }

    cout << "OUTPUT :"<<endl;


for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}