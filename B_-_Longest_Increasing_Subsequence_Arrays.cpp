#include <bits/stdc++.h>
using namespace std;
#define max_lim 500005
#define Mod 1000000007
vector<long long> f(max_lim + 1), fi(max_lim + 1);
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
void precalc()
{
    f[0] = 1;
    for (long long i = 1; i <= max_lim; i++)
    {
        f[i] = f[i - 1] * i % Mod;
        fi[i] = modInverse(f[i]);
    }
    fi[0] = fi[1];
    return;
}
void solve()
{
    int m, n;
    cin >> m >> n;
    long long ans = 0;
    long long p1 = 1;                    // n to the power x
    long long p2 = bigMod(n - 1, m - n); // n-1 to the power m-n-x
    long long mdinverse_n_1 = modInverse(n - 1);
    for (int x = 0; x <= m - n; x++)
    {
        if(x==m-n)
            p2 = 1;
        long long ncr = f[m - x - 1] * fi[n - 1] % Mod * fi[m - n - x] % Mod;
        ans = (ans + (((ncr * p1) % Mod) * p2) % Mod) % Mod;
        p1 = p1 * n % Mod;
        p2 = p2 * mdinverse_n_1 % Mod;
    }
    cout << (ans + Mod) % Mod << "\n";
    return;
}
int32_t main()
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