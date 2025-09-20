#include <bits/stdc++.h>
using namespace std;



int main()
{
    int a,b,c=0;
    cin>>a>>b;
   c=a+b;
   c=max(c,a+(a-1));
   c=max(c,b+(b-1));
    cout << c;
    return 0;
}