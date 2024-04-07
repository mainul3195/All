#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, rev;
int n;
vector<long long> c;
vector<int> indegree, done;
long long mn_cost, mn_node;
void dfs(int u)
{
    done[u] = 1;
    if(c[u]<mn_cost)
    {
        mn_cost = c[u];
        mn_node = u;
    }
    for (auto v : adj[u])
        if (!done[v])
            dfs(v);
    return;
}
void solve()
{
    cin >> n;
    adj = rev = vector<vector<int>>(n + 1);
    c = vector<long long>(n + 1);
    indegree = done = vector<int>(n + 1, 0);
    for (int u = 1; u <= n; u++)
    {
        int v;
        cin >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
        indegree[v]++;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            q.push(i);
    vector<int> ans;
    while (q.size())
    {
        int u = q.front();
        ans.push_back(u);
        done[u] = 2;
        q.pop();
        for (auto v : adj[u])
        {
            indegree[v]--;
            if (!indegree[v])
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!done[i])
        {
            mn_cost = 1000000009;
            dfs(i);
            vector<int> tmp;
            queue<int> q;
            q.push(mn_node);
            while(q.size())
            {
                int u = q.front();
                q.pop();
                tmp.push_back(u);
                done[u] = 2;
                for(auto v: rev[u])
                    if(done[v] ==1)
                        q.push(v);
            }
            while(tmp.size())
            {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    // cout << "ok\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}