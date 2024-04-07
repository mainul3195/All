#include <bits/stdc++.h>
using namespace std;

#define lim 10000000
int spf[lim + 1];
void smallest_pf()
{
    for (int i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (int j = i * i; j <= lim; j += 2 * i)
                spf[j] = i;
    for (int i = 3; i <= lim; i += 2)
        if (!spf[i])
            spf[i] = i;
    return;
}
#define Mod 1000000007
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
void solve()
{
    int n;
    cin >> n;
    map<long long, long long> ar, done;
    for (int _ = 0; _ < n; _++)
    {
        int m;
        cin >> m;
        map<long long, long long> mp;
        while (m--)
        {
            int a;
            cin >> a;
            while (a > 1)
            {
                int p = spf[a];
                int count = 0;
                while (!(a % p))
                {
                    a /= p;
                    count++;
                }
                if (count)
                    mp[p] += count;
            }
        }
        for (auto [p, c] : mp)
        {
            if (!(ar.count(p)))
                ar[p] = c;
            else
                ar[p] = min(ar[p], c);
            done[p]++;
        }
    }
    long long ans = 1;
    for (auto [p, c] : ar)
        if (done[p] == n)
            ans = ans * bigMod(p, c) % Mod;
    cout << ans << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    smallest_pf();
    solve();
    return 0;
}