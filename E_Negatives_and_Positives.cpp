#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long sum = 0, minus_count = 0, mn = 1000000009;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (x < 0)
        {
            minus_count++;
            x *= -1;
        }
        sum += x;
        mn = min(mn, x);
    }
    if (minus_count & 1)
        cout << sum - 2 * mn << "\n";
    else
        cout << sum << "\n";
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