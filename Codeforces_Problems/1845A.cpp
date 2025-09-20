#include <bits/stdc++.h>
using namespace std;



int main()
{int t;cin>>t;
while(t--)
{
    int n,k,x,i;cin>>n>>k>>x;
    if(x!=1){
        cout <<"yes"<<endl;
        cout<<n<<endl;
        for(i=0;i<n;i++)cout <<1<<" ";
        cout <<endl;
    }
    else if(k>1 && n%2==0)
    {
        cout <<"yes"<<endl;
        cout<<n/2<<endl;
        for(i=0;i<n;i+=2)cout <<2<<" ";
        cout <<endl;
    }
    else if(k>2 && n>1 && n%2==1)
    {
        cout <<"yes"<<endl;
        cout<<1+(n-3)/2<<endl;
        cout <<3;n-=3;
        for(i=0;i<n;i+=2)cout <<" "<<2;
        cout <<endl;
    }
    else {
        cout <<"NO"<<endl;
    }
   }   return 0;
}