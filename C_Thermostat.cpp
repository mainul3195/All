#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a == b)
        cout << "0\n";
    else if (abs(a - b) >= x)
        cout << "1\n";
    else
    {
        if (b > a)
        {
            int dif = b - a;
            // for 2
            if (b + x <= r || a - x >= l)
                cout << "2\n";
            // for 3
            else if (a + x <= r && b - x >= l)
                cout << "3\n";
            else
                cout << "-1\n";
        }
        else
        {
            int dif = a - b;
            // for 2
            if (a + x <= r || b - x >= l)
                cout << "2\n";
            // for 3
            else if (a - x >= l && b + x <= r)
                cout << "3\n";
            else
                cout << "-1\n";
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        // cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}