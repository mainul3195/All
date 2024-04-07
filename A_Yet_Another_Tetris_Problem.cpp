#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    bool ev = 0, od = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (j & 1)
            od = 1;
        else
            ev = 1;
    }
    if ((ev || od) && !(ev && od))
        cout << "YES\n";
    else
        cout << "NO\n";
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