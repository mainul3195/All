#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<vector<int>> adj, diradj;
vector<int> vis1, vis2, outgoings;
int dfs1(int u)
{
    int tot = 1;
    vis1[u] = 1;
    for (auto v : adj[u])
        if (!vis1[v])
            tot += dfs1(v);
    return tot;
}
int last_node(int u)
{
    if (vis2[u])
        return -1;
    vis2[u] = 1;
    if (diradj[u].size() == 0 || diradj[u][0] == u)
        return u;
    return last_node(diradj[u][0]);
}
void solve()
{
    int n;
    cin >> n;
    vis1 = vis2 = vector<int>(2 * n + 1, 0);
    adj = vector<vector<int>>(2 * n + 1);
    diradj = vector<vector<int>>(2 * n + 1);
    outgoings.clear();
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        outgoings.push_back(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
        diradj[u].push_back(v);
    }
    sort(outgoings.begin(), outgoings.end());
    long long ans = 1;
    for (int i = 1; i <= 2 * n; i++)
        if (!vis1[i])
        {
            long long nodes = dfs1(i);
            int lst_node = last_node(i);
            // cout << i << " " << nodes << " " << lst_node << "\n";
            if (lst_node == -1)
                ans = (ans * 2) % mod;
            else if (diradj[lst_node].size() == 0)
                ans = (ans * nodes) % mod;
        }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}