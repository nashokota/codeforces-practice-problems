#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    long long int s=0; int m_odd=INT_MAX;

    for(int i=0;i<n;i++)
    {
            s+=ar[i];
            if(ar[i] %2 == 1)
        m_odd= min(m_odd,ar[i]);
    }
    if(s%2 == 0)
    cout << s;
    else 
    {
        s=s-m_odd;
        cout<<s;
    }

    return 0;
}