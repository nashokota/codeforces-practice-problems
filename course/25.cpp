#include <bits/stdc++.h>
using namespace std;



int main()
{
    char X[100],Y[100];
    
    cin>>X>>Y;

    int lenx = strlen(X);
    int leny = strlen(Y);

int ln = min(lenx,leny);

for(int i=0;i<ln;i++)
{
    if(X[i]<Y[i])
    {
        cout << X <<endl;
        return 0;
    }
    else if(X[i]>Y[i])
    {
        cout << Y<<endl;
        return 0;
    }
}

if(lenx<=leny)
{
    cout << X <<endl;
}
else 
cout << Y<<endl;


    return 0;
}