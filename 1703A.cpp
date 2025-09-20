#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;cin>>t;
    while (t--)
    {
        string ss;
        cin>>ss;
        if(ss=="YES"|ss=="yES"||ss=="yes"||ss=="Yes"||ss=="YeS"||ss=="YEs"||ss=="yEs"||ss=="yeS")
        cout << "YES"<<endl;
        else
        cout << "NO"<<endl;
    }
    return 0;
}