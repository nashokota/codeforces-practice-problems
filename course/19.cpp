#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //int s=0;
    for(int i=0;i<n;i++)
    {
        s+=arr[i];
    }
    if(s>=0)
    {
        cout << s;
    }
    else{
        s=s*(-1);
        cout <<s;
    }
    return 0;
}