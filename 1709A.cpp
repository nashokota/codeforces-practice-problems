#include <bits/stdc++.h>
using namespace std;



int main()
{
    
    int t;
    cin >> t;
    while(t--){
        
    
    int arr[4];
    int key;
    int a,b,c;
    int ans=0;
     cin>>key;

    cin>>a>>b>>c;
    arr[1]=a;
    arr[2]=b;
    arr[3]=c;
    // cout << "a"<< a<<endl;
    // cout << "b"<< b<<endl;
    // cout << "c"<< c<<endl;

    // cout << "arr[1]"<< arr[1] <<endl;
    // cout << "arr[2]"<< arr[2] <<endl;
    // cout << "arr[3]"<< arr[3]<<endl;
    for( int i=1;i<=2;i++)
    {
        if(arr[key]==0)
        {
            ans=1;
            break;
        }
        key=arr[key];
        //cout << "new key =" << key << endl;
    }

    if(ans==0)
    cout<< "YES" << endl;
    if(ans==1)
    cout<< "NO" << endl;
    }
    return 0;
}