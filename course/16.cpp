#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    int divisor=0;
    for(int t=1;t<=n;t++)
    {
        if(n%t==0)
        divisor++;
    }
    if(divisor==2){
        return true;
    }
    else return false;
}

bool almost_prime(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            if(is_prime(i)){
                ans++;
            }
        }
    }
     if(ans==2)
        {
            return true;
        }
        else 
        {
            return false;
        }
}
int main()
{
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(almost_prime(i))
        {
m++;
        }
    }
    cout << m;
    return 0;
}