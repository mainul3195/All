#include <bits/stdc++.h>
using namespace std;
int n, g;
vector<vector<int>> adj, spTable;
vector<int> par, level;
void dfs(int u = 1, int p = 1, int l = 1)
{
    par[u] = p;
    level[u] = l;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u, l + 1);
}
int findLCA(int u, int v)
{
    if (level[u] > level[v])
        u ^= v ^= u ^= v;
    int mx = log2(n) + 2;
    for (int i = mx; level[v] - level[u] && i >= 0; i--)
    {
        if (level[v] - level[u] >= (1ll << i))
            v = spTable[v][i];
    }
    if (u == v)
        return u;
    for (int i = mx; par[u] != par[v] && i >= 0; i--)
    {
        if (spTable[u][i] != spTable[v][i])
        {
            u = spTable[u][i];
            v = spTable[v][i];
        }
    }
    return par[u];
}
int dis(int u, int v)
{
    int l = findLCA(u, v);
    return level[u] - level[l] + level[v] - level[l];
}
int calc(int a, int b, int c)
{
    int lab = findLCA(a, b);
    int lbc = findLCA(b, c);
    int lca = findLCA(c, a);
    return min({dis(a, b) + dis(lab, c), dis(b, c) + dis(lbc, a), dis(c, a) + dis(lca, b)});
}
void solve()
{
    cin >> n >> g;
    adj = vector<vector<int>>(n + 1, vector<int>());
    spTable = vector<vector<int>>(n + 1, vector<int>(log2(n) + 2, 0));
    par = vector<int>(n + 1);
    level = vector<int>(n + 1, 0);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    for (int i = 1; i <= n; i++)
        spTable[i][0] = par[i];
    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if ((level[j] - (1 << i)) > 0)
                spTable[j][i] = spTable[spTable[j][i - 1]][i - 1];
    }
    int k = 0;

    for (int i = 0; i < g; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << calc(a, b, c) << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}