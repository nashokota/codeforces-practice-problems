// Is Sorted ? //
#include <bits/stdc++.h>
using namespace std;

bool Is_sorted(int arr[] ,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[ i ]>arr[ i+1 ])
        {
            return false;
        }
    }
    return true ;
}

int main()
{
 int arr[]={4,8,13,16,20,25,28,33};
 int n= sizeof(arr)/sizeof(arr[0]) ;
 int k= Is_sorted(arr,n);
 if(k==1) cout << "SORTED";
 else cout << "NOT SORTED";
    return 0;
}