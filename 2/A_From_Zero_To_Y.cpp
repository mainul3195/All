#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int d;
    string s;
    cin >> d >> s;
    long long r = 0, ans = 0;
    for (auto i : s)
    {
        r = r * 10 + i - '0';
        ans += r / d;
        r %= d;
    }
    ans += r;
    cout << ans << "\n";
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