#include <bits/stdc++.h>
using namespace std;
#define inf 100000000
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> dist_from_1(n + 1, inf), dist_from_n(n + 1, inf);
    set<pair<long long, int>> st;
    dist_from_1[1] = 0;
    st.insert({0, 1});
    while (st.size())
    {
        auto [dis, u] = *st.begin();
        st.erase(st.begin());
        for (auto [v, w] : adj[u])
            if (dis + w < dist_from_1[v])
            {
                dist_from_1[v] = dis + w;
                st.insert({dis + w, v});
            }
    }
    dist_from_n[n] = 0;
    st.insert({0, n});
    while (st.size())
    {
        auto [dis, u] = *st.begin();
        st.erase(st.begin());
        for (auto [v, w] : adj[u])
            if (dis + w < dist_from_n[v])
            {
                dist_from_n[v] = dis + w;
                st.insert({dis + w, v});
            }
    }
    set<long long> d;
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, w] : adj[u])
        {
            d.insert(dist_from_1[u] + dist_from_n[v] + w);
            if (d.size() > 2)
            {
                auto it = d.end();
                d.erase(--it);
            }
        }
    }
    auto it = d.begin();
    it++;
    cout << *it << "\n";
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