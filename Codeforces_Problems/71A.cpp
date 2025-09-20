#include <bits/stdc++.h>
using namespace std;



int main()
{
    int a;
	cin>>a;
	for ( int i=0 ; i<=a ; i++ ) 
	{
		string s;
		cin>>s;
		if ( s.size() > 10 )
		{
			cout << s[0] << s.size() - 2 << s [ s.size()-1 ]<<endl;
		}
		
		else
		{
			cout << s << endl;
		}
	}
 
    return 0;
}