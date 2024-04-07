#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    int ans = 0;
    for (long long i = 1; i * i <= n; i++)
        ans++;
    for (long long i = 1; i * i * i <= n; i++)
        ans++;
    for (long long i = 1; i * i * i * i * i * i <= n; i++)
        ans--;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
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