#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,d,a[100];
    cin>>n ;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    d=abs(a[0]-a[n-1]);
    int x=n,y=1;
    for(i=0;i<n;i++) {
        if(d>abs(a[i]-a[i+1])) {
            d = abs(a[i + 1] - a[i]);
            x=i+1;
            y=i+2;
        }
    }
    cout<<x<<" "<<y<<endl;
}


