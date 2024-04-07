#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long w, h;
    cin >> w >> h;
    long long ans = 0;
    int k;
    cin >> k;
    long long mn, mx;
    cin >> mn;
    for (int i = 1; i < k; i++)
        cin >> mx;
    ans = max(ans, (mx - mn) * h);
    cin >> k;
    cin >> mn;
    for (int i = 1; i < k; i++)
        cin >> mx;
    ans = max(ans, (mx - mn) * h);
    cin >> k;
    cin >> mn;
    for (int i = 1; i < k; i++)
        cin >> mx;
    ans = max(ans, (mx - mn) * w);
    cin >> k;
    cin >> mn;
    for (int i = 1; i < k; i++)
        cin >> mx;
    ans = max(ans, (mx - mn) * w);
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