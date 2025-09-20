#include<iostream>
using namespace std;

int main(){
    int n,t;
    cin>>n>>t;
    string s;
    char temp;
    cin>>s;
    for(int i=0;i<t;i++){
        for(int j=1;j<n;j++){
            
            if(s[j-1]=='B' && s[j]=='G'){
               
            temp=s[j-1];
            s[j-1]=s[j];
            s[j]=temp;
            j++;
            
        }
            }
        }
    
    cout<<s<<endl;
}