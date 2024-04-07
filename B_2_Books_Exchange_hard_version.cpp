#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
int dfs(int u, int l)
{
    if (vis[u])
        return vis[u] = l;
    vis[u] = 1;
    int lvl;
    for (auto v : adj[u])
        lvl = dfs(v, l + 1);
    return vis[u] = lvl;
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    vis = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[i].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 0);
    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
    cout << "\n";
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