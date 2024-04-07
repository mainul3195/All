#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long dif, w, lf;
    nd() {}
    nd(long long a, long long b)
    {
        w = a;
        lf = b;
        dif = (w - w / 2) * lf;
    }
    bool operator<(const nd &a) const
    {
        return dif > a.dif;
    }
};
vector<vector<pair<int, long long>>> adj;
multiset<nd> st;
int n;
long long s;
long long tot_sum;
int dfs(int u = 1, int p = -1, long long w = 0, long long tot = 0)
{
    int tot_leaf = 0;
    for (auto [v, w] : adj[u])
        if (v != p)
            tot_leaf += dfs(v, u, w, tot + w);
    if (!tot_leaf)
    {
        tot_sum += tot;
        tot_leaf = 1;
    }
    if (~p)
        st.insert(nd(w, tot_leaf));
    return tot_leaf;
}
void init()
{
    tot_sum = 0;
    st.clear();
    adj = vector<vector<pair<int, long long>>>(n + 1);
    return;
}
void solve()
{
    cin >> n >> s;
    init();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs();
    int count = 0;
    while (tot_sum > s)
    {
        auto it = st.begin();
        auto [d, t, l] = *it;
        tot_sum -= d;
        st.erase(it);
        st.insert(nd(t / 2, l));
        count++;
    }
    cout << count << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}