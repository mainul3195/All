#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dis(n);
    for (auto &i : dis)
        i = 199999999;
    int t;
    cin >> t;
    dis[t] = 0;
    q.push({0, t});
    while (!q.empty())
    {
        auto [w, u] = q.top();
        q.pop();
        for (auto [w_, v] : adj[u])
        {
            int cur_cost = max(w, w_);
            if (cur_cost < dis[v])
            {
                dis[v] = cur_cost;
                q.push({cur_cost, v});
            }
        }
    }
    for (auto i : dis)
    {
        if (i > 100000000)
            cout << "Impossible\n";
        else
            cout << i << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}