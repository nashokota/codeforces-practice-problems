#include <bits/stdc++.h>
using namespace std;



int main()
{
    string ss;
    cin>>ss;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='H'||ss[i]=='Q'||ss[i]=='9')
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}