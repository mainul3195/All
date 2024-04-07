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
struct dt
{
    int v;
    long long w;
    int c;
};
vector<vector<dt>> adj;
multiset<nd> st[3];
vector<long long> c[3];
int n;
long long s, ans;
long long tot_sum;
int dfs(int u = 1, int p = -1, long long w = 0, long long tot = 0, int cst = -1)
{
    int tot_leaf = 0;
    for (auto [v, w, c] : adj[u])
        if (v != p)
            tot_leaf += dfs(v, u, w, tot + w, c);
    if (!tot_leaf)
    {
        tot_sum += tot;
        tot_leaf = 1;
    }
    if (~p)
        st[cst].insert(nd(w, tot_leaf));
    return tot_leaf;
}
void init()
{
    tot_sum = ans = 0;
    st[1].clear();
    st[2].clear();
    adj = vector<vector<dt>>(n + 2);
    c[1].clear();
    c[2].clear();
    c[1].push_back(0);
    c[2].push_back(0);
    return;
}
void process(int i)
{
    auto it = st[i].begin();
    auto [d, t, l] = *it;
    st[i].erase(it);
    if (t > 1)
        st[i].insert(nd(t / 2, l));
    return;
}
void solve()
{
    cin >> n >> s;
    init();
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        long long w;
        cin >> u >> v >> w >> c;
        adj[u].push_back({v, w, c});
        adj[v].push_back({u, w, c});
    }
    dfs();
    for (int i = 1; i <= 2; i++)
    {
        while (st[i].size())
        {
            auto it = st[i].begin();
            c[i].push_back(c[i].back() + (*it).dif);
            process(i);
        }
    }
    long long need = tot_sum - s;
    ans = 2000000000;
    for (int i = 0; i < c[1].size(); i++)
    {
        int j = lower_bound(c[2].begin(), c[2].end(), need - c[1][i]) - c[2].begin();
        if (j == c[2].size())
            j = 2000000000;
        ans = min(ans, (long long)i + (long long)2 * j);
    }
    cout << ans << "\n";
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