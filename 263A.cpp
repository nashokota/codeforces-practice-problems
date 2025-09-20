#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j;
    int arr[5][5];

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (arr[i][j] == 1)
            {
                cnt = abs(i - 2) + abs(j - 2);
                cout << cnt <<endl;
                return 0;
            }
        }
    }

   

    return 0;
}
