#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, m, l, r;
    cin >> a >> m >> l >> r;
    l -= a;
    r -= a;
    if (l > 0)
        cout << (r / m - (l - 1) / m) << "\n";
    else if (l == 0)
        cout << (r / m + 1) << "\n";
    else
    {
        long long lw = (l - m + 1) / m * m;
        l -= lw;
        r -= lw;
        if (l > 0)
            cout << (r / m - (l - 1) / m) << "\n";
        else if (l == 0)
            cout << (r / m + 1) << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}