#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;cin>>t;
    while(t--)
    {
        int arr[4];
        for(int i=0;i<4;i++)
        {
            cin>>arr[i];
        }
        
        int x = max(arr[0],arr[1]);
        int xx = min(arr[0],arr[1]);
        int y = max(arr[2],arr[3]);
        int yy = min(arr[2],arr[3]);

        if(xx<y && yy<x)
        {
            cout <<"YES"<<endl;
        }
        else 
        {
            cout << "NO" <<endl;
        }
    }
    return 0;
}