#include <bits/stdc++.h>
using namespace std;
#define lim 10000020
bitset<lim / 2 + 2> bit;
vector<long long> primes;
void make_primes()
{
    primes.push_back(2);
    for (int i = 3; i * i < lim; i += 2)
        if (!bit[i / 2])
            for (int j = i * i; j < lim; j += 2 * i)
                bit[j / 2] = 1;
    for (int i = 3; i < lim; i += 2)
        if (!bit[i / 2])
            primes.push_back(i);
    return;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return b * bigMod(b, p - 1);
    long long t = bigMod(b, p / 2);
    return t * t;
}
void solve()
{
    long long a, b, l;
    cin >> a >> b >> l;
    map<long long, int> mpa, mpb, mpl;
    for (auto p : primes)
    {
        if (p * p > a)
            break;
        int count = 0;
        while (!(a % p))
        {
            count++;
            a /= p;
        }
        if (count)
            mpa[p] = count;
    }
    if (a > 1)
        mpa[a] = 1;

    for (auto p : primes)
    {
        if (p * p > b)
            break;
        int count = 0;
        while (!(b % p))
        {
            count++;
            b /= p;
        }
        if (count)
            mpb[p] = count;
    }
    if (b > 1)
        mpb[b] = 1;

    for (auto p : primes)
    {
        if (p * p > l)
            break;
        int count = 0;
        while (!(l % p))
        {
            count++;
            l /= p;
        }
        if (count)
            mpl[p] = count;
    }
    if (l > 1)
        mpl[l] = 1;
    // checking for impossible
    for (auto [p, c] : mpa)
        if (max(c, mpb[p]) > mpl[p])
        {
            cout << "impossible\n";
            return;
        }
    for (auto [p, c] : mpb)
        if (max(c, mpa[p]) > mpl[p])
        {
            cout << "impossible\n";
            return;
        }
    long long ans = 1;
    for (auto [p, c] : mpl)
    {
        if (max(mpa[p], mpb[p]) == c)
            continue;
        ans = ans * bigMod(p, c);
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_primes();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}