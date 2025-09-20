#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
   
    string t;
    getline(cin, t);
    int k = s.size();
    int l = t.size();
    reverse(s.begin(), s.end());
    
    
    
    if (k != l){
        cout << "NO";
    }
    else{
        int i=0;
        while(s[i]==t[i]){
            i++;
        }
     cout<<i;

        if((i)==(k)){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
       
    }
}