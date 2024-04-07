#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    if (!(n % 9))
        cout << n + (n - 1) / 9 << " " << n + n / 9 << "\n";
    else
        cout << n + (n - 1) / 9 << "\n";
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