#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (x > a)
    {
        if (a + c >= x)
            c -= x - a;
        else
        {
            cout << "NO\n";
            return;
        }
    }
    // cout << c << "\n";
    if (c + b < y)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}