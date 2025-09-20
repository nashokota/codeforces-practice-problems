#include <bits/stdc++.h>
using namespace std;



int main()
{
    string a;
    string b="1111111";
    string c="0000000";
    cin>>a;
    size_t found1 =a.find(b);
    size_t found2 =a.find(c);
    if(found1!=string::npos || found2!=string::npos)
    {
        cout <<"YES";
    }
    else{
        cout <<"NO";
    }
    return 0;
}