#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c0, c1, h;
    string s;
    cin >> n >> c0 >> c1 >> h >> s;
    long long ans = 0;
    for (auto i : s)
    {
        if (i == '0')
            ans += min(c0, h + c1);
        else
            ans += min(c1, h + c0);
    }
    cout << ans << '\n';
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