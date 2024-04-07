#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.rbegin(), v.rend());
    int cnt = 0;
    int prev = 0;
    int sum = 0;
    int mn = 2147483647;
    for (auto i : v)
    {
        prev++;
        if (min(mn, i) * prev >= x)
        {
            mn = 2147483647;
            cnt++;
            prev = 0;
        }
        else
            mn = min(mn, i);
    }
    cout << cnt << "\n";
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