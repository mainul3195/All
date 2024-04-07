#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
bool possible()
{
    if ((a + c) % 2 == 0 && ((a + c) / 2) % b == 0)
        return 1;
    if ((b + b - a) > 0 && (b + b - a) % c == 0)
        return 1;
    if ((b - c + b) > 0 && (b - c + b) % a == 0)
        return 1;
    return 0;
}
void solve()
{
    cin >> a >> b >> c;
    if (possible())
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