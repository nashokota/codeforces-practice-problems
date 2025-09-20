// find missing element from 1st n numbers //
#include <bits/stdc++.h>
using namespace std;



int main()
{
    int arr[]={1,2,3,4,5,6,8,9,10,11,12};
    int len = sizeof(arr)/sizeof(arr[0]);

    int i,sum=0;
    for(i=0;i<len;i++)
    {
        sum+=arr[i];
    }
    int y=arr[i-1];
    y=y*(y+1)/2;
    

    cout << "missing element is :"<< (y-sum);
    return 0;
}