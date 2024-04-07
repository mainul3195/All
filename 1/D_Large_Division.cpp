#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a;
    long long b;
    cin >> a >> b;
    int i = a[0] == '-';
    if (b < 0)
        b *= -1;
    long long r = 0;
    while (i < a.size())
        r = (r * 10 + a[i++] - '0') % b;
    if (r)
        cout << "not divisible\n";
    else
        cout << "divisible\n";
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