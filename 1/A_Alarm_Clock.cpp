#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b)
        cout << b << "\n";
    else
    {
        if (c <= d)
            cout << "-1\n";
        else
            cout << b + (a - b + c - d - 1) / (c - d) * c << "\n";
    }

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