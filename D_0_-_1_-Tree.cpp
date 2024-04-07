#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> par0, par1, one, zero, vis1, vis0;
vector<vector<int>> adj1, adj0;
int getpar1(int u)
{
    if (par1[u] == u)
        return u;
    return par1[u] = getpar1(par1[u]);
}
int getpar0(int u)
{
    if (par0[u] == u)
        return u;
    return par0[u] = getpar0(par0[u]);
}
void dfs0(int u)
{
    vis0[u] = 1;
    zero[u] = zero[getpar0(u)];
    for (auto v : adj0[u])
        if (!vis0[v])
            dfs0(v);
    return;
}
void dfs1(int u)
{
    vis1[u] = 1;
    one[u] = one[getpar1(u)];
    for (auto v : adj1[u])
        if (!vis1[v])
            dfs1(v);
    return;
}
void solve()
{
    cin >> n;
    adj1 = adj0 = vector<vector<int>>(n + 1);
    vis1 = vis0 = par0 = par1 = one = zero = vector<long long>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        par0[i] = par1[i] = i;
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if (c)
        {
            int pu = getpar1(u);
            int pv = getpar1(v);
            if (one[pv] < one[pu])
            {
                par1[pv] = pu;
                one[pu] += one[pv] + 1;
                one[pv] = 0;
            }
            else
            {
                par1[pu] = pv;
                one[pv] += one[pu] + 1;
                one[pu] = 0;
            }
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        else
        {
            int pu = getpar0(u);
            int pv = getpar0(v);
            if (zero[pv] < zero[pu])
            {
                par0[pv] = pu;
                zero[pu] += zero[pv] + 1;
                zero[pv] = 0;
            }
            else
            {
                par0[pu] = pv;
                zero[pv] += zero[pu] + 1;
                zero[pu] = 0;
            }
            adj0[u].push_back(v);
            adj0[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis0[i])
            dfs0(i);
        if (!vis1[i])
            dfs1(i);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int p0 = getpar0(i);
        int p1 = getpar1(i);
        if (zero[p0] && vis0[p0] == 1)
        {
            ans += zero[p0] * (zero[p0] + 1);
            vis0[p0] = 2;
        }
        if (one[p1] && vis1[p1] == 1)
        {
            ans += one[p1] * (one[p1] + 1);
            vis1[p1] = 2;
        }
        ans += zero[p0] * one[p1];
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}