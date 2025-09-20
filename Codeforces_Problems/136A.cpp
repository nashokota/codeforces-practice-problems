#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, a;
    cin >> t;
    int arr[t];
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    for(int j=1;j<=t;j++)
    {
        for(int i=0;i<t;i++)
        {
            if(j==arr[i])
            {
                cout<<i+1<<" ";
            }
        }
    }

}
