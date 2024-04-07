#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 30)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        if (n - 30 != 6 && n - 30 != 10 && n - 30 != 14)
            cout << "6 10 14 " << n - 30 << "\n";
        else
            cout << "6 10 15 " << n - 31 << "\n";
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