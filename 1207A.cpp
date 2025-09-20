#include <bits/stdc++.h>
using namespace std;

void fun()
{
    int pro1=0;
    int b,p,f;
    cin>>b>>p>>f;

    int h,c;
    cin>>h>>c;
if(b>=2){
    if(h>c)
    {
        for (;p>0 && b>=2;p--,b-=2)
            {pro1 = pro1 + h;}
    }
    else
    {
        for(;f>0 && b>=2;f--,b-=2)
            {pro1 = pro1 + c;}
    }
     for (;p>0 && b>=2;p--,b-=2)
            {pro1 = pro1 + h;}
    for(;f>0 && b>=2;f--,b-=2)
            {pro1 = pro1 + c;}
  cout << pro1<<endl;          
}
else
cout << "0"<<endl;

}

int main()
{
 int t;
 cin>>t;
 while (t--)
 {
    fun();
 }
    
    return 0;
}