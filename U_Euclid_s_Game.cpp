#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    while (cin >> a >> b && (a || b))
    {
        if (a < b)
            a ^= b ^= a ^= b;
        long long ta = a, tb = b;
        int count = 0;
        bool done = 0;
        while (tb)
        {
            if (ta / tb >= 2)
            {
                if (count & 1)
                    cout << "Ollie wins\n";
                else
                    cout << "Stan wins\n";
                done = 1;
                break;
            }
            count++;
            ta = ta % tb;
            ta ^= tb ^= ta ^= tb;
        }
        if (!done)
        {
            if (count & 1)
                cout << "Stan wins\n";
            else
            {
                if (a / b >= 2)
                    cout << "Stan wins\n";
                else
                    cout << "Ollie wins\n";
            }
        }
    }
    return 0;
}