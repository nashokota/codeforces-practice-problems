#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;

    int ar[n];
    int c0=0,c5=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(ar[i]==0) c0++;
        else c5++;
    }
    if(c0==0)
    {
        cout << -1;
        return 0;
    }
    else {
        if(c5<9)
        {
            cout <<0;
            return 0;
        }
        else {
            c5=c5/9;
            while(c5!=0)
            {
                cout <<555555555;
                c5--;
            }
            while(c0--)
            {
                cout <<0;
            }
        }
    }
    return 0;
}