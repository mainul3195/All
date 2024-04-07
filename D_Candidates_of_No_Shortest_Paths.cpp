#include <bits/stdc++.h>
using namespace std;
int n, m;
struct nd
{
    int u, v, w;
};
void solve()
{
    cin >> n >> m;
    int adj[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = 20000000;
        }
    vector<nd> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
        edges.push_back({u, v, w});
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << adj[i][j] << " ";
    //     cout << "\n";
    // }
    int count = 0;
    for (auto [u, v, w] : edges)
        if (adj[u][v] < w)
            count++;
    cout << count << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}