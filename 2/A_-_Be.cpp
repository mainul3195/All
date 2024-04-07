#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int t, k;
        cin >> t >> k;
        indegree[t] += k;
        while (k--)
        {
            int a;
            cin >> a;
            adj[a].push_back(t);
        }
    }
    set<int> q;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            q.insert(i);
    while (q.size())
    {
        int t = *q.begin();
        cout << t << " ";
        q.erase(q.begin());
        for (auto v : adj[t])
        {
            indegree[v]--;
            if (!indegree[v])
                q.insert(v);
        }
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}