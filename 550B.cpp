#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sol=0;
    for(int m=0;m<(1 << n);m++)
    {
        int pb=0;
        int t_diff=0;
        int min_diff=INT_MAX;
        int max_diff=INT_MIN;

        for(int i=0;i<n;i++)
        {
            if((m >> i)&1)
            {
                pb++;
                t_diff+=arr[i];
                min_diff=min(min_diff,arr[i]);
                max_diff=max(max_diff,arr[i]);
            }
        }
        if(pb>=2 && t_diff>=l && t_diff<=r && abs(max_diff-min_diff)>=x)
        {
            sol++;
        }
    }

    cout << sol<<endl;
return 0;
}