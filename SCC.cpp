// // kosaraju

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, rev;
int n, m;
vector<int> vis, stck, scc;
void dfs(int u, vector<vector<int>> &graph)
{
    vis[u] = 1;
    for (auto v : graph[u])
        if (!vis[v])
            dfs(v, graph);
    // cout << u << "\n";
    stck.push_back(u);
}
void find_scc()
{
    vis = vector<int>(n + 1, 0);
    scc = vector<int>(n + 1, 0);
    dfs(1, adj);
    vis = vector<int>(n + 1, 0);
    int token = 1;
    auto order = stck;
    stck.clear();
    while (order.size())
    {
        int i = order.back();
        if (!vis[i])
        {
            dfs(i, rev);
            while (stck.size())
            {
                scc[stck.back()] = token;
                stck.pop_back();
            }
            token++;
        }
        order.pop_back();
    }
    vector<pair<int, int>> janina;
    for (int i = 1; i <= n; i++)
        janina.push_back({scc[i], i});
    sort(janina.begin(), janina.end());
    for (auto [s, n] : janina)
        cout << "SCC no " << s << ": " << n << "\n";
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1, vector<int>());
    rev = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    find_scc();
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

// Tarjans

// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> adj, rev;
// int n, m, tme = 0, token;
// vector<int> dis, low, stck, scc, instck;
// void dfs(int u)
// {
//     stck.push_back(u);
//     instck[u] = 1;
//     low[u] = dis[u] = ++tme;
//     for (auto v : adj[u])
//     {
//         if (dis[v])
//         {
//             if (instck[v])
//                 low[u] = min(low[u], dis[v]);
//         }
//         else
//         {
//             dfs(v);
//             low[u] = min(low[u], low[v]);
//         }
//     }
//     if (low[u] == dis[u])
//     {
//         token++;
//         int cur;
//         do
//         {
//             cur = stck.back();
//             stck.pop_back();
//             instck[cur] = 0;
//             scc[cur] = token;
//         } while (cur != u);
//     }
// }
// void find_scc()
// {
//     dis = vector<int>(n + 1, 0);
//     low = vector<int>(n + 1, 0);
//     scc = vector<int>(n + 1, 0);
//     instck = vector<int>(n + 1, 0);
//     dfs(1);
//     // for (int i = 1; i <= n; i++)
//     //     cout << i << " -> " << dis[i] << "/" << low[i] << "\n";
//     // for (int i = 1; i <= n; i++)
//     //     cout << i << " -> " << scc[i] << "\n";
//     vector<pair<int, int>> janina;
//     for (int i = 1; i <= n; i++)
//         janina.push_back({scc[i], i});
//     sort(janina.begin(), janina.end());
//     for (auto [s, n] : janina)
//         cout << "SCC no " << s << ": " << n << "\n";
// }
// void solve()
// {
//     cin >> n >> m;
//     adj = vector<vector<int>>(n + 1, vector<int>());
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }
//     find_scc();
//     return;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     solve();
//     return 0;
// }