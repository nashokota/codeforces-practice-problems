#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long int n;
    cin>>n;

    int a,b,c=1,d=0;
    //  if(n==4 )
    //     {
    //         cout << "NO";
    //         return 0;
            
    //     }

    //     if(n==7)
    //     {
    //         cout << "NO";
    //         return 0;
            
    //     }
    while(n!= 0)
    {
       
        
        a=n%10;

        if(a == 4 || a == 7)
        {
d++;
        }
          n=n/10;
        
        }

       
    
    if(d==4||d==7){
        cout << "YES";
    }
   else {cout <<"NO";}
    return 0;
}