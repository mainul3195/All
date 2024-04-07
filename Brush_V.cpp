// using bellmann ford

#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int start, end, weight;
};
int n, m;
void solve()
{
    cin >> n >> m;
    vector<edge> edg(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edg.push_back({u, v, w});
        edg.push_back({v, u, w});
    }
    vector<int> dis(n + 1);
    for (auto &i : dis)
        i = INT_MAX;
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto [u, v, w] : edg)
            if (dis[u] != INT_MAX && dis[u] + w < dis[v])
                dis[v] = dis[u] + w;
    }
    for (auto [u, v, w] : edg)
        if (dis[u] != INT_MAX && dis[u] + w < dis[v])
        {
            cout << "Impossible\n"; // negative cycle detected
            return;
        }
    if (dis[n] == INT_MAX)
        cout << "Impossible\n";
    else
        cout << dis[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}