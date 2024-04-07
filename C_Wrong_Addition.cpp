#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, s;
    cin >> a >> s;
    bool ok = 1;
    string ans;

    while (a || s)
    {
        if (a && !s)
        {
            ok = 0;
            break;
        }
        int la = a % 10;
        int ls = s % 10;
        a /= 10;
        s /= 10;
        if (la > ls)
        {
            ls = ls + 10 * (s % 10);
            s /= 10;
        }
        if (la > ls || ls - la > 9)
        {
            ok = 0;
            break;
        }
        // cout << la << " " << ls << "\n";
        ans += 48 + (ls - la);
    }
    reverse(ans.begin(), ans.end());
    long long num = 0;
    for (auto i : ans)
        num = num * 10 + i - 48;
    if (ok)
        cout << num << "\n";
    else
        cout << "-1\n";
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