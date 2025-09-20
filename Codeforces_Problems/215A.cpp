// recheck the code //

#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;cin>>n;
    int arp[n];
    for(int i=0;i<n;i++)
    {
        cin>>arp[i];
    }
    int m;cin>>m;
    int arx[m];
    for(int i=0;i<n;i++)
    {
        cin>>arx[i];
    }

    int cnt=0;
    int ans=INT_MIN;
    int ans2,ans3=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((arx[j]/arp[i])>ans && arx[j]%arp[i]==0)
          {
            ans=arx[j]/arp[i];
          }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((arx[j]/arp[i])==ans && arx[j]%arp[i]==0)
          {
            cnt++;
          }
        }
    }
    //cnt++;
    cout << cnt <<endl;
    return 0;
}







