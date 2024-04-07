#include <bits/stdc++.h>
using namespace std;
#define lim 10000000
#define ckbit(x) (fLd[(x) / 64] & (1 << ((x) % 64) / 2))
#define cngbit(x) (fLd[(x) / 64] |= (1 << ((x) % 64) / 2))
int fLd[lim / 64 + 2];
vector<long long> prime;
void sieve()
{
    prime.push_back(2);
    for (long long i = 3; i * i <= lim; i += 2)
        if (!ckbit(i))
            for (long long j = i * i; j <= lim; j += 2 * i)
                cngbit(j);
    for (long long i = 3; i <= lim; i += 2)
        if (!ckbit(i))
            prime.push_back(i);
    return;
}
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
    long long a, b, l;
    cin >> a >> b >> l;
    long long tl = lcm(a, b);
    if (l % tl)
        cout << "impossible\n";
    else
    {
        map<long long, long long> pf;
        for (int i = 0; prime[i] * prime[i] <= tl; i++)
        {
            int count = 0;
            while (!(tl % prime[i]))
            {
                count++;
                tl /= prime[i];
            }
            if (count)
                pf[prime[i]] = count;
        }
        if (tl > 1)
            pf[tl] = 1;
        long long ans = 1;
        for (int i = 0; prime[i] * prime[i] <= l; i++)
        {
            int count = 0;
            while (!(l % prime[i]))
            {
                count++;
                l /= prime[i];
            }
            if (count && count > pf[prime[i]])
            {
                while (count--)
                    ans *= prime[i];
            }
        }
        if (l > 1 && !pf[l])
            ans *= l;
        cout << ans << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}