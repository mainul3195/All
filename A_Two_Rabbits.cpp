#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (!((y - x) % (a + b)))
        cout << (y - x) / (a + b) << "\n";
    else
        cout << "-1\n";
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