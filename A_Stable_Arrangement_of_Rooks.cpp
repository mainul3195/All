#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if ((n + 1) / 2 < k)
    {
        cout << "-1\n";
        return;
    }
    vector<vector<char>> grid(n, vector<char>(n));
    for (auto &i : grid)
        for (auto &j : i)
            j = '.';
    for (int i = 0; k && i < n; i += 2, k--)
        grid[i][i] = 'R';
    for (auto i : grid)
    {
        for (auto j : i)
            cout << j;
        cout << "\n";
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