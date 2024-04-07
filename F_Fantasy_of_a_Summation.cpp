#include <bits/stdc++.h>
using namespace std;
long long n, k, mod;
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return b * bigMod(b, p - 1) % mod;
    long long t = bigMod(b, p / 2);
    return t * t % mod;
}
void solve()
{
    cin >> n >> k >> mod;
    long long mul = k * bigMod(n, k - 1) % mod;
    // cout << "mul = " << mul << "\n";
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        ans = (ans + a * mul % mod) % mod;
    }
    cout << (ans + mod) % mod << "\n";
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
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}