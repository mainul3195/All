#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    map<int, int> mp;
    for (auto i : v)
        mp[i]++;
    vector<int> sng;
    for (auto i : v)
        if (mp[i] == 1)
            sng.push_back(i);
    sort(sng.begin(), sng.end());
    if (sng.empty())
        cout << "-1\n";
    else
    {
        for (int i = 0; i < n; i++)
            if (v[i] == sng[0])
            {
                cout << i + 1 << "\n";
                return;
            }
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