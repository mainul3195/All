#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    long long int n, t, i, k, flag, d1, d2;

    cin >> t;
    while (t--)

    {

        cin >> n;

        if (n % 2 != 0)
        {
            cout << "YES"
                 << "\n";
        }

        else
        {
            for (i = 2; i <= log2(n); i++)
            {
                if (n % i == 0)
                {
                    cout << i << "\n";
                    d1 = i;
                    d2 = n / i;
                    cout << d1 << " " << d2 << "\n";
                    if (d1 % 2 == 1 || d2 % 2 == 1)
                        flag = 1;
                }
            }

            if (flag == 1)
            {
                cout << "YES"
                     << "\n";
            }

            else
                cout << "NO"
                     << "\n";
        }
    }
    return 0;
}