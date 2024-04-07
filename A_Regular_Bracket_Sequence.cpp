#include <bits/stdc++.h>
using namespace std;
string s;
bool Ok()
{
    if (s.size() % 2)
        return 0;
    int forward = 0, backward = 0;
    for (auto i : s)
    {
        if (i == '(' || i == '?')
            forward++;
        else
            backward++;
        if (backward > forward)
            return 0;
    }
    forward = backward = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '?' || s[i] == ')')
            backward++;
        else
            forward++;
        if (forward > backward)
            return 0;
    }
    return 1;
}
void solve()
{
    cin >> s;
    if (Ok())
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