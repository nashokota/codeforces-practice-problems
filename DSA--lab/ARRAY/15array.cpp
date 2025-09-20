//missing one elements randomly //
#include <bits/stdc++.h>
using namespace std;



int main()
{
    int arr[]={6,7,8,9,10,11,13,14,15,16,17};
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++)
    {
        if(arr[i]-i!=arr[0])
        {
            cout << "missing element :"<< arr[i]-1;
            return 0;
        }
    }
    return 0;
}