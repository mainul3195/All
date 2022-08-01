#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, long long>>> adj;
vector<long long> dis, ans;
long long n, last, mx;
void dfs(int u, long long ds = 0)
{
    ans[u] = max(ans[u], ds);
    dis[u] = ds;
    if (ds > mx)
    {
        mx = ds;
        last = u;
    }
    for (auto [v, w] : adj[u])
        if (dis[v] == -1)
            dfs(v, ds + w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        adj = vector<vector<pair<int, long long>>>(n + 1, vector<pair<int, long long>>());
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        ans = vector<long long>(n + 1, 0);
        dis = vector<long long>(n + 1, -1);
        mx = -1;
        dfs(1);
        dis = vector<long long>(n + 1, -1);
        mx = -1;
        dfs(last);
        dis = vector<long long>(n + 1, -1);
        mx = -1;
        dfs(last);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
    return 0;
}