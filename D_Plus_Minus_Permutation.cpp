#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x, y;
    cin >> n >> x >> y;
    long long dx = n / x;
    long long dy = n / y;
    long long both = n / (x / __gcd(x, y) * y);
    dx -= both;
    dy -= both;
    // cout << dx << " " << dy << " " << both << "\n";
    cout << (2 * n + 1 - dx) * dx / 2 - dy * (dy + 1) / 2 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}