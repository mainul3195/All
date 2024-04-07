#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
struct nd
{
    int n, dis;
    bool operator<(const nd &a) const
    {
        return dis > a.dis || (dis == a.dis && n > a.n);
    }
};
vector<int> dist, par;
void dfs(int u = 1, int d = 0, int p = -1)
{
    par[u] = p;
    dist[u] = d;
    for (auto v : adj[u])
        if (v != p)
            dfs(v, d + 1, u);
    return;
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist = par = vector<int>(n + 1);
    dfs();
    set<nd> st;
    for (int i = 1; i <= n; i++)
        if (dist[i] > 2)
            st.insert({i, dist[i]});
    int cnt = 0;
    while (st.size())
    {
        auto it = st.begin();
        auto [lnode, ldis] = *it;
        int node = par[lnode], dis = ldis - 1;
        auto it3 = st.find({node, dis});
        if (it3 != st.end())
            st.erase(it3);
        for (auto v : adj[node])
        {
            auto it2 = st.find({v, dist[v]});
            if (it2 != st.end())
                st.erase(it2);
        }
        cnt++;
    }
    cout << cnt << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}