// linear search //
#include <bits/stdc++.h>
using namespace std;

int searchfunc(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[]={2,4,6,8,10,12,14,44};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=10;

    int pos = searchfunc(arr,n,x);

    if(pos== -1)
    {
        cout << "Element not Found ";
    }
    else
    {
        cout << "Element found at position :"<<pos+1<<endl;
    }

    return 0;
}