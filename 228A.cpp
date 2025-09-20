#include <bits/stdc++.h>

using namespace std;
 
int main() {
    
    
    int s1, s2, s3, s4;
    
    cin>>s1>>s2>>s3>>s4;
 
 
    int uc = 4;
    if (s1 == s2 || s1 == s3 || s1 == s4) uc--;
    if (s2 == s3 || s2 == s4) uc--;
    if (s3 == s4) uc--;
 
    int uv = 4 - uc;
 
    cout << uv ;
    return 0;
}
