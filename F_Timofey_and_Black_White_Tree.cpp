#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;
int n, c0, ans;
vector<vector<int>> adj;
int cs[200005], dis[200005];
void dfs1(int u, int l)
{
    dis[u] = l;
    for (auto v : adj[u])
        if (dis[v] == -1)
            dfs1(v, l + 1);
    return;
}

void dfs(int u, int p = -1)
{
    if (dis[u] >= ans)
        return;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        if (dis[v] > dis[u] + 1)
        {
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
        else
            ans = min(ans, dis[u] + dis[v] + 1);
    }
}
void solve()
{
    cin >> n >> c0;
    adj = vector<vector<int>>(n + 1);
    memset(dis, -1, sizeof(int) * (n + 2));
    for (int i = 1; i < n; i++)
        cin >> cs[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(c0, 0);
    ans = inf;
    for (int i = 1; i < n; i++)
    {
        int c = cs[i];
        dis[c] = 0;
        dfs(c, 0);
        cout << ans << " ";
    }
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