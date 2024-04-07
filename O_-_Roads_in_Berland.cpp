#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (auto &v : adj)
        for (auto &i : v)
            cin >> i;
    int q;
    cin >> q;
    while (q--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int temp_cost = adj[i][u] + adj[v][j] + w;
                adj[j][i] = adj[i][j] = min(adj[i][j], temp_cost);
            }
        long long tot = 0;
        for (auto v : adj)
            for (auto i : v)
                tot += i;
        cout << tot / 2 << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}