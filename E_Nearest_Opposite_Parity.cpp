#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> ans, vis, a;
void find(int parity)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
        if ((a[i] & 1) == parity)
            q.push(i), vis[i] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (vis[v] == -1 && ((a[v] & 1) != parity))
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
    }
    for (int i = 0; i < n; i++)
        if (vis[i] > 0)
            ans[i] = vis[i];
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj = vector<vector<int>>(n);
    ans = vis = vector<int>(n, -1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        if (i + x < n)
            adj[i + x].push_back(i);
        if (i - x >= 0)
            adj[i - x].push_back(i);
    }
    find(0);
    vis = vector<int>(n, -1);
    find(1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}