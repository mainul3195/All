#include <bits/stdc++.h>
using namespace std;
vector<int> v, par;
vector<vector<int>> adj;
int getpar(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = getpar(par[u]);
}
void join(int u, int v)
{
    int pu = getpar(u);
    int pv = getpar(v);
    if (pu > pv)
        pu ^= pv ^= pu ^= pv;
    if (pu != pv)
        par[pv] = pu;
    return;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    par = vector<int>(n + 2);
    adj = vector<vector<int>>(n + 2);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    v = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        join(v[x], v[y]);
    }
    for (int i = 1; i <= n; i++)
    {
        int p = getpar(v[i]);
        adj[p].push_back(v[i]);
    }
    for (auto &vec : adj)
        sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; i++)
    {
        int p = getpar(v[i]);
        v[i] = adj[p].back();
        adj[p].pop_back();
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
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