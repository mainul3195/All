#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n, k;
vector<int> frnde, dof;

int frst(int u = 1, int par = -1)
{
    if (frnde[u])
    {
        dof[u] = 0;
        return 1;
    }
    for (auto v : adj[u])
        if (v != par)
            dof[u] = min(dof[u], frst(v, u));
    return 1 + dof[u];
}
bool dfs(int u = 1, int par = -1, int dis = 0)
{
    if (frnde[u])
        return 0;
    if (adj[u].size() == 1 && u != 1)
        return 1;
    bool ok = 0;
    for (auto v : adj[u])
        if (v != par)
            ok |= dfs(v, u, dis + 1);
    if (ok && dis < dof[u])
        return 1;
    return 0;
}
void solve()
{
    cin >> n >> k;
    adj = vector<vector<int>>(n + 1, vector<int>());
    frnde = vector<int>(n + 1, 0);
    dof = vector<int>(n + 1);
    for (auto &i : dof)
        i = 214748364;
    for (int i = 0; i < k; i++)
    {
        int j;
        cin >> j;
        frnde[j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    frst();
    if (dfs())
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