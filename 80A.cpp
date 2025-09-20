#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to sqrt(n)
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

// Driver code
int main()
{
    int n, m;
    cin >> n >> m;

    for (n = n + 1; n <= m; n++)
    {
        if (isPrime(n))
        {
            if (n == m)
            {
                cout << "YES";
                return 0;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}

