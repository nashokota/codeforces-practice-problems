#include <bits/stdc++.h>
using namespace std;



int main()
{
    char s[10005];
    cin>>s;
    int ln = strlen(s);
    int arr[30]={0};
int cn=0;
    for(int i=1;i<=ln;i++)
    {
        int x = s[i-1]-97;
        if(arr[x]==0)
        {
           arr[x]=1;
           cn++;
        }
    }
    if(cn%2==0)
    cout << "CHAT WITH HER!"<<endl;
    else
    cout <<"IGNORE HIM!"<<endl;
    return 0;
}