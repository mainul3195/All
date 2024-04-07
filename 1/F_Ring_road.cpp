#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
map<pair<int, int>, int> mp;
int dfs(int u = 1, int par = -1)
{
    if (u == 1 && par != -1)
        return 0;
    int mn = 2147483647;
    for (auto v : adj[u])
        if (v != par)
            mn = min(mn, (mp.find({u, v}) != mp.end() ? mp[{u, v}] : 0) + dfs(v, u));
    return mn;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u, v}] = w;
    }
    cout << dfs() << "\n";
    return 0;
}