#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
int bfs(int u)
{
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    int count1 = 0, count2 = 0;
    while (!q.empty())
    {
        int nd = q.front();
        if (vis[nd] == 1)
            count1++;
        else
            count2++;
        q.pop();
        for (auto v : adj[nd])
        {
            if (!vis[v])
            {
                if (vis[nd] == 1)
                    vis[v] = 2;
                else
                    vis[v] = 1;
                q.push(v);
            }
        }
    }
    return max(count1, count2);
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(20004, vector<int>());
    vis = vector<int>(20004, -1);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        vis[u] = vis[v] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= 20000; i++)
        if (!vis[i])
            ans += bfs(i);
    cout << ans << "\n";
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
        solve();
    }
    return 0;
}