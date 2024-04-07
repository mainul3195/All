#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    int mn = 10000000, mx = -1;
    for (auto &i : v)
    {
        cin >> i;
        mn = min(i, mn);
        mx = max(i, mx);
    }

    int border_min = min(v[0], v[n - 1]);
    int border_max = max(v[0], v[n - 1]);

    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += abs(v[i] - v[i - 1]);
    if (mn > 1)
        ans += min(2 * (mn - 1), border_min - 1);
    if (x > mx)
        ans += min(2 * (x - mx), x - border_max);

    cout << ans << "\n";

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