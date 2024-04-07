#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
long long dfs(int u, int p)
{
    long long tot = 0;
    for (auto v : adj[u])
        if (v != p)
            tot += dfs(v, u) + adj[v].size() - 1;
    long long child = adj[u].size() - (u != 1);
    tot += child * (child - 1) / 2;
    return tot;
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1, -1) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}