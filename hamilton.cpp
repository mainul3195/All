#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> path, vis;
void hamilton(int u)
{
    vis[u] = 1;
    path.push_back(u);
    if (path.size() == n)
    {
        for (auto i : path)
            cout << i << " ";
        cout << '\n';
    }
    for (auto v : adj[u])
        if (!vis[v])
            hamilton(v);
    path.pop_back();
    vis[u] = 0;
    return;
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1, vector<int>());
    vis = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        hamilton(i);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}