#include <bits/stdc++.h>
using namespace std;

#define lim 10000005

vector<long long> spf(lim + 1);
void sieve()
{
    for (long long i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (long long i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (long long j = i; j <= lim; j += 2 * i)
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
    long long n;
    cin >> n;
    unordered_map<long long, long long> p;
    unordered_map<long long, long long> it_t;
    for (long long _ = 0; _ < n; _++)
    {
        long long m;
        cin >> m;
        unordered_map<long long, long long> tmp;
        while (m--)
        {
            long long a;
            cin >> a;
            while (a > 1)
            {
                long long k = spf[a];
                long long count = 0;
                while (!(a % k))
                {
                    count++;
                    a /= k;
                }
                tmp[k] += count;
            }
        }
        for (auto [i, j] : tmp)
        {
            it_t[i]++;
            p[i] = p[i] ? min(p[i], j) : j;
        }
    }
    long long g = 1;
    for (auto [a, b] : p)
    {
        if (it_t[a] != n)
            continue;
        g = (g * bigMod(a, b)) % Mod;
    }
    cout << g << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    long long t = 1, tc = 0;
    // cin >> t;
    while (t--)
    {
        // cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/