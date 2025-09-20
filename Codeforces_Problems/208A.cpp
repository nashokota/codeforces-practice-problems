#include <bits/stdc++.h>
using namespace std;



int main()
{
    string ss;cin>>ss;
    int ff=1;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='W' && ss[i+1]=='U' && ss[i+2]=='B')
        {
            i+=2;
            if(ff==0)
            {
                cout << " ";
            }

        }
        else {
            ff=0;
            cout <<ss[i];
        }
    }
    return 0;
}