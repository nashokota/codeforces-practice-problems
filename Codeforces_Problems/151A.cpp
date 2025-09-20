#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int xx = (k*l)/nl;
    int yy = c*d;
    int zz = p/np;
    int tt = min(xx,yy);
    tt = min(tt,zz);
    cout << tt/n ;
    return 0;
}