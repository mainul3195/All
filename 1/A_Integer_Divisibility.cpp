#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    int count = 0;
    int num = 0;
    while (num || !count)
    {
        count++;
        num = num * 10 + d;
        num %= n;
    }
    cout << count << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
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