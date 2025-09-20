#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,k;
    cin >>n>>k;
    int p=0;
    int c=0;
    for(int i=1;i<=n;i++)
    {
        p+=5*i;
        if(k+p<=240)
        {
            c++;
        }
        else
        break;
    }
    cout << c;
    return 0;
}