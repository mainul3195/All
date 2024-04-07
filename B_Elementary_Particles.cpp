#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    cin >> n;
    vector<int> v(n);
    int mx = -1;
    for (auto &i : v)
    {
        cin >> i;
        mx = max(mx, i);
    }
    vector<int> prev(mx + 1, -1);
    vector<int> mndist(mx + 1);
    for (auto &i : mndist)
        i = n;
    for (int i = 0; i < n; i++)
    {
        if (prev[v[i]] != -1)
            mndist[v[i]] = min(mndist[v[i]], i - prev[v[i]]);
        prev[v[i]] = i;
    }
    int ans = 0;
    for (auto i : mndist)
        ans = max(ans, n - i);
    if (ans)
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