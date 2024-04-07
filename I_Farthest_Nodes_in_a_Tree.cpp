#include <bits/stdc++.h>
using namespace std;
struct pr
{
    long long a, b;
    bool operator<(const pr &x) const { return a < x.a || (a == x.a && b < x.b); }
};
vector<vector<pr>> adj;
vector<int> vis;
int n, last, mx;
void dfs(int u, int ds = 0)
{
    vis[u] = ds;
    if (ds > mx)
    {
        mx = ds;
        last = u;
    }
    for (auto [v, w] : adj[u])
        if (vis[v] == -1)
            dfs(v, ds + w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        cin >> n;
        adj = vector<vector<pr>>(n, vector<pr>());
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vis = vector<int>(n, -1);
        mx = -1;
        dfs(0);
        vis = vector<int>(n, -1);
        mx = -1;
        dfs(last);
        cout << mx << "\n";
    }
    return 0;
}