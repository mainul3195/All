#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> cat;
int dfs(int u, int par, int strike)
{
    // cout << u << " " << par << " " << strike << "\n";
    if (cat[u])
        strike++;
    else
        strike = 0;
    // cout << "after " << strike << "\n";
    if (strike > m)
        return 0;
    if (adj[u].size() == 1 && par != -1)
        return 1;
    int tot = 0;
    for (auto v : adj[u])
        if (v != par)
            tot += dfs(v, u, strike);
    return tot;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1, vector<int>());
    cat = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cat[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1, -1, 0) << "\n";
    return 0;
}