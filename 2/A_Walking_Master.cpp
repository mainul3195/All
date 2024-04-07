#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long C = b - a;
    if (c + C > d || d < b)
        cout << "-1\n";
    else
        cout << abs(b - d) + abs(d - C - c) << "\n";

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