#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> par, previous_experience_of_parent, no_of_child, pending;
pair<int, int> getpar(int u)
{
    int tmp_u = u, cur_experience = 0;
    int tot_pending, tot_previous;
    tot_pending = tot_previous = 0;
    while (1)
    {
        tot_pending += pending[u];
        tot_previous += previous_experience_of_parent[u];
        if (par[u] == u)
            break;
        u = par[u];
    }
    if (tmp_u == u)
        return {u, pending[u]};
    pending[tmp_u] = tot_pending - pending[u];
    previous_experience_of_parent[tmp_u] = tot_previous;
    par[tmp_u] = u;
    return {u, tot_pending - tot_previous};
}
void join(int u, int v)
{
    auto [pu, _] = getpar(u);
    auto [pv, __] = getpar(v);
    if (pu == pv)
        return;
    if (no_of_child[pu] < no_of_child[pv])
    {
        swap(u, v);
        swap(pu, pv);
    }
    par[pv] = pu;
    previous_experience_of_parent[pv] += pending[pu];
    no_of_child[pu] += no_of_child[pv] + 1;
    no_of_child[pv] = 0;
    return;
}
void solve()
{
    cin >> n >> q;
    par = vector<int>(n + 1);
    previous_experience_of_parent = vector<int>(n + 1, 0);
    pending = vector<int>(n + 1, 0);
    no_of_child = vector<int>(n + 1, 0);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x, v;
            cin >> x >> v;
            auto [p, ex] = getpar(x);
            // cout << p << " " << ex << "\n";
            pending[p] += v;
        }
        else if (s == "get")
        {
            int x;
            cin >> x;
            auto [_, ex] = getpar(x);
            // cout << _ << " " << ex << "\n";
            cout << ex << "\n";
        }
        else
        {
            int u, v;
            cin >> u >> v;
            join(u, v);
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}