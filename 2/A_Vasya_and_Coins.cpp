#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;
    if (!a)
        cout << 1 << "\n";
    else
        cout << 2 * b + a + 1 << "\n";
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