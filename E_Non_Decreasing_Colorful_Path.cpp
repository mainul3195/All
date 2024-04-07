#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int val[200005], ans[200005];
int n, m;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans[1] = 1;
    priority_queue<pair<int, int>> q;
    q.push({1, 1});
    while (q.size())
    {
        auto [a, u] = q.top();
        q.pop();
        if (ans[u] > a)
            continue;
        for (auto v : adj[u])
        {
            int nw = 0;
            if (a)
            {
                if (val[v] > val[u])
                    nw = a + 1;
                else if (val[v] == val[u])
                    nw = a;
            }
            if (nw > ans[v])
            {
                ans[v] = nw;
                q.push({nw, v});
            }
        }
    }
    cout << ans[n] << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}