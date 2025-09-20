#include <bits/stdc++.h>
using namespace std;

bool solve(string ss){
    for(int i=0;i<(int)ss.size();i++)
    {
        if(ss[i] != '1' && ss[i] != '4')
        {
            return false;
        }
    }
    if(ss[0]!='1') return false;

    if(ss.find("444") != ss.npos) return false;

    return true;
    
}

int main()
{
    string ss;cin>>ss;

    if(solve(ss)){
        cout<<"YES"<<endl;
    }   
    else {
        cout <<"NO"<<endl;
    }
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;
// #define  ll long long
// #define AS iostream::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// int main()
// {
//     AS
//     string s;cin>>s;
//     bool flag= true;
//     for (int i = 0; i < s.size(); ++i) {
//         if(s[i]!='1'&&s[i]!='4')
//             flag= false;
//         if(s[i]=='4'&&s[i+1]=='4'&&s[i+2]=='4')
//             flag= false;
//         if(s[0]=='4')
//             flag= false;
//     }
//     if(flag== false){
//         cout<<"NO\n";
//     }
//     else{
//         cout<<"YES\n";
//     }
//     return 0;
//     }

		  				    		  		  			  		 		