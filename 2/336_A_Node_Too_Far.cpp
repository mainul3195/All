#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> level;
int tc = 0;
void solve()
{

    // taking input and coordinate compression
    vector<pair<int, int>> v(n);
    map<int, int> mp;
    set<int> st;
    int cnt = 0;
    for (auto &[a, b] : v)
    {
        cin >> a >> b;
        st.insert(a);
        st.insert(b);
    }
    for (auto i : st)
        mp[i] = cnt++;
    for (auto &[a, b] : v)
        a = mp[a], b = mp[b];

    // making adjacency list
    adj = vector<vector<int>>(st.size(), vector<int>());
    for (auto [a, b] : v)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // processing each query
    int from, ttl;
    while (cin >> from >> ttl && (from || ttl))
    {
        level = vector<int>(st.size(), -1);
        int tmp = from;
        from = mp[from];
        queue<int> q;
        q.push(from);
        level[from] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
                if (level[v] == -1 && level[u] < ttl)
                {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
        }
        int ans = 0;
        for (int i = 0; i < st.size(); i++)
            if (level[i] == -1)
                ans++;
        cout << "Case " << ++tc << ": " << ans << " nodes not reachable from node " << tmp << " with TTL = " << ttl << ".\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n)
        solve();
    return 0;
}