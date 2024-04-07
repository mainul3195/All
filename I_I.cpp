#include <bits/stdc++.h>
using namespace std;
#define max_lim 1000006
#define Mod 1000000007
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
    long long n, m, k;
    cin >> n >> m >> k;
    if (m != k + 1)
    {
        cout << "0\n";
        return;
    }
    long long black_points = n - m;
    long long i = k - 1;
    long long j = 0;
    long long ans = 0;
    while (black_points)
    {
        ans = (ans + nCr(i, j) % Mod) % Mod;
        // cout << black_points << " -> " << ans << "\n";
        black_points--;
        i++, j++;
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    solve();
    return 0;
}