#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(3, 0);
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        v[j % 3]++;
    }
    int tot = 0;
    bool ok = 1;
    int avg = (v[0] + v[1] + v[2]) / 3;
    while (ok)
    {
        ok = 0;
        for (int i = 0; i < 3; i++)
            if (v[i] > avg)
            {
                tot += v[i] - avg;
                v[(i + 1) % 3] += v[i] - avg;
                v[i] = avg;
                ok = 1;
            }
    }
    cout << tot << "\n";
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