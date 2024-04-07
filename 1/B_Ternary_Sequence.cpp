#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x1, x2, y1, y2, z1, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    long long ans = 0;
    long long tmp;
    tmp = min(z1, y2);
    ans += 2 * tmp;
    z1 -= tmp;
    y2 -= tmp;
    tmp = min(y1, x2 + y2);
    ans -= 2 * (y1 - tmp);
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