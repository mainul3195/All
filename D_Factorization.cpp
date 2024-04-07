#include <bits/stdc++.h>
using namespace std;
#define max 300005
#define mod 1000000007LL
long long fact[max];
void precalc()
{
    fact[0] = 1;
    for (int i = 1; i < max; i++)
        fact[i] = fact[i - 1] * i % mod;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    long long tmp = bigMod(b, p / 2);
    tmp = tmp * tmp % mod;
    if (p & 1)
        tmp = tmp * b % mod;
    return tmp;
}
long long mod_inverse(long long x)
{
    return bigMod(x, mod - 2);
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    long long lim = sqrt(m + .5);
    long long ans = 1;
    for (long long i = 2; i * i <= m; i++)
    {
        int cnt = 0;
        while (m % i == 0)
        {
            cnt++;
            m /= i;
        }
        if (cnt)
        {
            // cout << cnt << " -> " << ans << " " << fact[n + cnt - 1] << " " << fact[cnt] << " " << fact[n - 1] << " : ";
            ans = (ans * (fact[n + cnt - 1]) % mod * mod_inverse(fact[cnt]) % mod * mod_inverse(fact[n - 1]) % mod) % mod;
        }
        // cout << ans << "\n";
    }
    if (m != 1)
        ans = (ans * (fact[n + 1 - 1]) * mod_inverse(fact[1]) % mod * mod_inverse(fact[n - 1]) % mod) % mod;
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