#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int arr[n]={0};

    int m,p;
    cin>>m;
    int arX[m];
    for(int i=0;i<m;i++)
    {
        cin>>arX[i];
        if(arr[arX[i]-1]==0)
        {
            arr[arX[i]-1]=10;
        }
    }
    cin>>p;
    int arY[p];
    for(int i=0;i<p;i++)
    {
        cin>>arY[i];
        if(arr[arY[i]-1]==0)
        {
            arr[arY[i]-1]=10;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            cout << "Oh, my keyboard!"<<endl;
            return 0;
        }
    }
    cout << "I become the guy."<<endl;
    return 0;
}