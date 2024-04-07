#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int a, b, c, d, e;
    void inp()
    {
        cin >> a >> b >> c >> d >> e;
    }
    bool operator>(const nd &x) const
    {
        int cnt = (a < x.a) + (b < x.b) + (c < x.c) + (d < x.d) + (e < x.e);
        return cnt >= 3;
    }
};
void solve()
{
    int n;
    cin >> n;
    nd w = {2147483647, 2147483647, 2147483647, 2147483647, 2147483647}, tmp;
    vector<nd> v(n);
    for (auto &i : v)
        i.inp();
    int ans = -1;
    for (int i = 0; i < n; i++)
        if (v[i] > w)
        {
            ans = i + 1;
            w = v[i];
        }
    bool ok = 1;
    for (int i = 0; i < n; i++)
        if (ans != i + 1)
        {
            ok &= (w > v[i]);
            if (!ok)
                break;
        }
    if (ok)
        cout << ans << "\n";
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