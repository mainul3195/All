#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> cost, visited, parent;
int max_cost = 0, farthest_node;
void dfs(int u, int cst = 0)
{
    visited[u] = 1;
    cst += cost[u];
    if (cst > max_cost)
    {
        max_cost = cst;
        farthest_node = u;
    }
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            dfs(v, cst);
        }
    }
    return;
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    cost = vector<int>(n + 1, 1);
    visited = vector<int>(n + 1, 0);
    parent = vector<int>(n + 1, 0);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tot_dis = 0;
    dfs(1);
    // cout << max_cost << "jg\n";
    int a = farthest_node;
    max_cost = 0;
    parent = vector<int>(n + 1, 0);
    visited = vector<int>(n + 1, 0);
    dfs(a);
    tot_dis += max_cost;
    int b = farthest_node;
    visited = vector<int>(n + 1, 0);
    for (int i = b; i; i = parent[i])
        cost[i] = 0;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
        tmp += cost[i];
    if (!tmp)
    {
        cout << n - 1 << "\n"
             << a << " " << b << " ";
        for (int i = 1; i <= n; i++)
            if (i != a && i != b)
            {
                cout << i << "\n";
                return;
            }
    }
    max_cost = 0;
    dfs(a);
    tot_dis += max_cost;
    // cout << max_cost << "\n";
    cout << tot_dis - 1 << "\n"
         << a << " " << b << " " << farthest_node << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}