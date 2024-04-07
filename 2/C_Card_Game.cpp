#include <bits/stdc++.h>
using namespace std;
// complexity: O(n)
// Must call precalc
#define max_lim 100
#define Mod 998244353
vector<long long> f(max_lim + 1);
void precalc()
{
    f[0] = 1;
    for (long long i = 1; i <= max_lim; i++)
        f[i] = f[i - 1] * i % Mod;
    return;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod - 2);
}
long long nCr(long long n, long long r)
{
    return (((f[n] * modInverse(f[r])) % Mod) * modInverse(f[n - r])) % Mod;
}
void solve()
{
    int n;
    cin >> n;
    long long ans1 = nCr(n - 1, n / 2 - 1), ans2 = 0;
    int p = n / 2;
    int i, j;
    for (i = 3, j = 4; p - i >= 0; i += 2, j += 4)
    {
        ans1 = (ans1 + nCr(n - j, p - i)) % Mod;
        ans1 = (ans1 + nCr(n - j - 1, p - i)) % Mod;
    }
    for (i = 2, j = 2; p - i >= 0; i += 2, j += 4)
    {
        ans2 = (ans2 + nCr(n - j, p - i)) % Mod;
        ans2 = (ans2 + nCr(n - j - 1, p - i)) % Mod;
    }
    cout << ans1 << " " << ans2 << " 1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}