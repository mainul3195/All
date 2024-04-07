#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> v(s.size() + 2, 0);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            v[i + 1] = 1;
    for (int i = 1; i < s.size() + 2; i++)
        v[i] += v[i - 1];
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    int mn = min(v[s.size()], (int)s.size() - v[s.size()]);
    // cout << mn << "\n";
    for (int i = 1; i <= s.size(); i++)
    {
        mn = min({mn, v[s.size()] - v[i] + i - v[i], v[i - 1] + (int)s.size() - i + 1 - v[s.size()] + v[i - 1]});
        // cout << i << " " << mn << "\n";
    }
    cout << mn << "\n";

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

0 1 2 3 4 5 6
0 0 0 1 2 2 2
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