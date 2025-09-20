#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int mi11 (int a,int c,int d)
{
    int x=min(a,c);
    int y=min(c,d);
    return min(x,y);
}
int mi22(int a,int b)
{
    return min(a,b);
}
int main()
{
   int a,b,c,d;
   cin >> a>>b>>c>>d;
    int min = mi11(a,c,d);
     int t=min;
     

     a=a-min;

    min = mi22(a,b);
    // int sum2 = 32*minn;
   // int total = ;
    cout << 256*t+32*min ;

    //cout << min <<endl;
    return 0;
}