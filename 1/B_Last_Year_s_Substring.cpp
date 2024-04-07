#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    string tar = "2020";
    bool ok = 0;
    for (int i = 0; i <= 4; i++)
    {
        if (s.substr(0, i) == tar.substr(0, i) && s.substr(n - 4 + i, 4 - i) == tar.substr(i, 4 - i))
        {
            ok = 1;
            break;
        }
    }
    if (ok)
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