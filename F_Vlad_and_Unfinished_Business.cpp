#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> needed;
int n, k;
int x, y;
int dfs1(int u = x, int par = -1)
{
    int tot = 0;
    // cout << u << " ";
    for (auto v : adj[u])
    {
        if (v != par)
            tot += dfs1(v, u);
    }
    // cout << tot << "\n";
    return tot + (u != x && (tot != 0 || needed[u] == 1));
}
bool found = 0;
int dis(int u = x, int par = -1, int ds = 0)
{
    if(u==y)
        return ds;
    int tmp = 0;
    for(auto v: adj[u])
    {
        if(v!=par)
            tmp = dis(v, u, ds + 1);
        if(tmp)
            return tmp;
    }
    return 0;
}

void solve()
{
    cin >> n >> k >> x >> y;
    adj = vector<vector<int>>(n + 1, vector<int>());
    needed = vector<int>(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int u;
        cin >> u;
        needed[u] = 1;
    }
    needed[y] = 1;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << 2*dfs1() - dis() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}