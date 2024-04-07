#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> degree;
vector<int> vis;
vector<int> path;

int find_source()
{
    vector<int> odds;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] & 1)
            odds.push_back(i);
    }
    if (odds.size() == 2)
        return odds[0];
    if (odds.size())
        return -1;
    return 1;
}
void add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
}
void del_edge(int u, int v)
{
    degree[u]--;
    degree[v]--;
    adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
}
int node_count(int u)
{
    vis[u] = 1;
    int count = 0;
    for (auto v : adj[u])
        if (!vis[v])
            count += node_count(v);
    return count + 1;
}
bool bridge(int u, int v)
{
    vis.assign(n + 1, 0);
    int init = node_count(u);
    vis.assign(n + 1, 0);
    del_edge(u, v);
    int after = node_count(u);
    add_edge(u, v);
    return init != after;
}
void find_path(int u)
{
    path.push_back(u);
    if (adj[u].size() == 1)
    {
        int v = *adj[u].begin();
        del_edge(u, v);
        find_path(v);
    }
    for (auto v : adj[u])
    {
        if (!bridge(u, v))
        {
            del_edge(u, v);
            find_path(v);
            return;
        }
    }
}
void find_eular_path()
{
    cin >> n >> m;
    degree = vector<int>(n + 1, 0);
    adj = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    int source = find_source();
    if (source == -1)
    {
        cout << "No Eular Path Exists.\n";
        return;
    }
    find_path(source);
    cout << "path -> ";
    for (auto i : path)
        cout << i << " ";
    cout << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    find_eular_path();
    return 0;
}