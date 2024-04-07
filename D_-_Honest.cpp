#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    set<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            q.insert(i);
    while (q.size())
    {
        int t = *q.begin();
        ans.push_back(t);
        q.erase(q.begin());
        for (auto v : adj[t])
        {
            indegree[v]--;
            if (!indegree[v])
                q.insert(v);
        }
    }
    if (ans.size() != n)
        cout << "Sandro fails.\n";
    else
    {
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}