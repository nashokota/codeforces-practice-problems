//Array Traversal
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[10];
    for (int i=0;i<10;i++)
    {
        //arr[i]=i+1;
        //*(arr+i)=i+1;
        i[arr]=i+1;
    }
    cout << " values :"<<endl;
    for(int &n:arr)
    {
        cout << n <<" "<<endl;
    }
    cout <<endl;
    for(int i=0;i<10;i++)
    {
        cout << i[arr] <<' ';
    }
    return 0;
}