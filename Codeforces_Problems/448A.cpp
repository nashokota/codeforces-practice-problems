#include <bits/stdc++.h>
using namespace std;



int main()
{
 int a1,a2,a3;cin>>a1>>a2>>a3;
 int cup =a1+a2+a3;
 int b1,b2,b3;cin>>b1>>b2>>b3;
 int med =b1+b2+b3;
 int shelf ;cin>>shelf;
 int n = ceil((float)cup/5.0) + ceil((float)med/10.0);
 //cout << n;
 if(n<=shelf) cout <<"YES";
 else cout <<"NO";  
    return 0;
}