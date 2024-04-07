#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
long long ncr[2003][2003], dp[1003][1003];
long long nCr(int n, int r)
{
    if (n < r)
        return 0;
    if (n == r || r == 0)
        return 1;
    if (~ncr[n][r])
        return ncr[n][r];
    return ncr[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
}
#define max_lim 1000006
vector<long long> f(max_lim + 1);
long long okdone(int n, int k)
{
    if (k == 1 || n == k)
        return 1;
    if (~dp[n][k])
        return dp[n][k];
    return dp[n][k] = (okdone(n - 1, k) * k % mod + okdone(n - 1, k - 1)) % mod;
}
int n, m, k;
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % mod;
}

long long modInverse(long long n)
{
    return bigMod(n, mod - 2);
}
long long nCr_b(long long n, long long r)
{
    if (n < r)
        return 0;
    return (((f[n] * modInverse(f[r])) % mod) * modInverse(f[n - r])) % mod;
}
void solve()
{
    memset(ncr, -1, sizeof(ncr));
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    long long ans = 0;
    // cout << okdone(3, 2) << "\n";
    if (m == 1)
        ans = bigMod(k, n);
    else
        for (int x = n; x; x--)
            for (int y = x; y >= 0; y--)
            {
                // cout << x << " " << y << endl;
                // cout << nCr_b(k, 2 * x - y) << endl;
                (ans += nCr_b(k, 2 * x - y) * nCr(2 * x - y, x - y) % mod * nCr(x, x - y) % mod * okdone(n, x) % mod * okdone(n, x) % mod * f[x] % mod * f[x] % mod * bigMod(y, n * (m - 2) % mod)) %= mod;
                // cout << x << " : " << y << " -> " << ans << " " << nCr(k, 2 * x - y) << "\n";
            }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    for (long long i = 1; i <= max_lim; i++)
        f[i] = f[i - 1] * i % mod;
    solve();
    return 0;
}