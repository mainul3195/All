#include <bits/stdc++.h>
using namespace std;

#define lim 10000020
#define ckbit(x) (fLd[(x) / 32] & (1 << ((x) % 32)))
#define cngbit(x) (fLd[(x) / 32] |= (1 << ((x) % 32)))
int fLd[lim / 32 + 2];

vector<long long> primes;
void sieve()
{
    cngbit(0);
    cngbit(1);
    primes.push_back(2);
    for (int i = 4; i <= lim; i += 2)
        cngbit(i);
    for (long long i = 3; i * i <= lim; i += 2)
        if (!ckbit(i))
            for (long long j = i * i; j <= lim; j += 2 * i)
                cngbit(j);
    for (long long i = 3; i <= lim; i += 2)
        if (!ckbit(i))
            primes.push_back(i);
    return;
}
void solve()
{
    int n;
    cin >> n;
    auto it = upper_bound(primes.begin(), primes.end(), n);
    int ans = 0;
    while (it != primes.begin())
    {
        it--;
        if (*it < n / 2)
            break;
        if (!ckbit(n - *it))
            ans++;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t = 1, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
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