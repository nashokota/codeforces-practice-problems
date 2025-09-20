#include <bits/stdc++.h>
using namespace std;


int main()
{
    int k,r,i;
    int x=0;
    cin>>k>>r;
    for(i=1;i;)
    {
        x=i*k;
        //cout <<x<<endl;
        if( x%10==0 || x%10==r ){
            break;
        }
       
        i++;
    } 
   // cout <<k<<r<<x;  
 cout << i ;
    return 0;
}
