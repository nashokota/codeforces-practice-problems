// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     char s1[100];
//     cin>>s1;
//     char s2[100];cin>>s2;
     
//     int len = strlen(s1);
// char out[len];
//     for(int i=0;i<len;i++)
//     {
//         if(s1[i]==s2[i])
//         {
//            cout <<0;
//         }
//         else 
//         {
//             cout <<1;
//         }
//     }


//     return 0;
// }


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    // if (s1.length() != s2.length())
    // {
    //     cout << "Input strings have different lengths." << endl;
    //     return 1;
    // }

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[i])
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }

    return 0;
}
