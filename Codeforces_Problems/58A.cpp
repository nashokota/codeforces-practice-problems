#include <bits/stdc++.h>
using namespace std;



int main()
{
    string ss;cin>>ss;
    int cnt=0;
    for(int i=0;i<ss.size();i++)
    {
        switch(cnt)
        {
            case 0:
                if(ss[i]=='h')
                cnt++;
                break;
            case 1:
                if(ss[i]=='e')
                cnt++;
                break;
            case 2:
                if(ss[i]=='l')
                cnt++;
                break;
            case 3:
                if(ss[i]=='l')
                cnt++;
                break;
            case 4:
                if(ss[i]=='o')
                cnt++;
                break;
                
        }
    }
    if(cnt==5)
    {
        cout <<"YES"<<endl;
    }
    else{
        cout <<"NO"<<endl;
    }
      return 0;
}