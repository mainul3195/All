#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dis;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dis.push_back(max({i + j, m - 1 - j + i, n - 1 - i + j, n + m - i - j - 2}));
    sort(dis.begin(), dis.end());
    for (int i = dis.size() - n * m; i < dis.size(); i++)
        cout << dis[i] << " \n"[i == dis.size() - 1];
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