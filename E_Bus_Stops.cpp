#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
long long gcd(long long a, long long b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
void solve()
{
    cin >> n >> x >> y;
    vector<pair<long long, long long>> v(n - 1);
    for (auto &[a, b] : v)
        cin >> a >> b;
    long long l = 1;
    for (auto [a, b] : v)
        l = lcm(l, a);
    // cout << " -> " << l << "\n";
    vector<long long> ans(l, 0);
    for (int i = 0; i < l; i++)
    {
        // cout << i << " -> ";
        long long tot = x + i;
        for (auto [p, t] : v)
        {
            tot += (tot + p - 1) / p * p - tot + t;
            // cout << tot << " ";
        }
        // cout << "\n";
        tot += y;
        ans[i] = tot;
    }
    int q;
    cin >> q;
    while (q--)
    {
        long long x;
        cin >> x;
        cout << x / l * l + ans[x % l] << "\n";
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