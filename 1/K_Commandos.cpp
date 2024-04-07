#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis, dis;
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (vis[v] == -1)
            {
                vis[v] = vis[u] + 1;
                dis[v] += vis[v];
                q.push(v);
            }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        int n, m;
        cin >> n >> m;
        adj = vector<vector<int>>(n, vector<int>());
        dis = vector<int>(n, 0);
        vis = vector<int>(n, -1);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int s, d;
        cin >> s >> d;
        bfs(s);
        vis = vector<int>(n, -1);
        bfs(d);
        int mx = 0;
        for (auto i : dis)
            mx = max(mx, i);
        cout << mx << "\n";
    }
    return 0;
}