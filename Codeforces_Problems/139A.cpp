#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int arr[7];
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
    }   
    int t;
    while(n>0)
    {
        for(int i=0;i<7;i++)
        {
            if(n<=0)
            {
                break;
            }
            else{
                n=n-arr[i];
              //  cout << "n = "<<n<<endl;
                t=i+1;
            }
        }
    }
    cout <<t;
    return 0;
}