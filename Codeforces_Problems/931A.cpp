#include <bits/stdc++.h>
using namespace std;



int main()
{ 
int j;
int d;
int m;
    int a,b;
    cin>>a>>b;
    if(a>b)
    {
        
        d =(a-b);
        m =d/2;
     //   int k=0;
    if (d%2==0)
    {
        j=m*(m+1);
       cout << j;
    }
    else
    {
          j=(m*(m+1)+m+1);
        cout << j;
     }
    }   

    if(b>a)
    {
       
         d =(b-a);
         m =d/2;
        //int k=0;
    if (d%2==0)
    {
        j=m*(m+1);
       cout << j;
    }
    else
    {
           j=(m*(m+1)+m+1);
        cout << j;
    }
    }   
    return 0;
}