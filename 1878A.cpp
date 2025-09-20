/*
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m,n;cin>>m>>n;
    int arr[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    map<int,int>mp;
    for(int it:arr)
    {
        mp[it]++;
    }
    int max=0;
    int maxele=arr[0];
    for(const auto &entry : mp)
    {
        if(entry.second>max)
        {
            max=entry.second;
            maxele=entry.first;
        }
    }
    if(maxele==n)
    {
        cout <<"YES"<<endl;
    }
    else 
    {
        cout << "NO"<<endl;
    }
}

int main()
{
    int t;cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
*/



/*
#include <iostream>
#include <vector>
#include <map>

int main() {
    // Sample array
    std::vector<int> array = {1, 3, 1, 3, 2, 1, 3, 3, 3, 4, 2, 4, 4, 4, 4};

    // Map to store the frequency of each element
    std::map<int, int> frequencyMap;

    // Populate the map with the frequency of each element
    for (int num : array) {
        frequencyMap[num]++;
    }

    // Find the element with the highest occurrence
    int maxCount = 0;
    int mostFrequentElement = array[0];

    for (const auto &entry : frequencyMap) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostFrequentElement = entry.first;
        }
    }

    // Output the result
    std::cout << "The element with the highest occurrence is: " << mostFrequentElement << std::endl;
    std::cout << "It appears " << maxCount << " times." << std::endl;

    return 0;
}

*/


#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;cin>>t;
    while(t--)
    {
        int m,n;cin>>m>>n;
        bool ans=0;
        for(int i=0;i<m;i++)
        {
            int p;cin>>p;if(p==n)ans=1;
        }
        if(ans)cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}