#include <bits/stdc++.h>
using namespace std;
int n, m, src, t = -1, v1, v2, cnt = 0, found = 0;
vector<vector<int>> adj;
vector<int> par, rt;
void dfs(int u, int p = -1, int root = -1)
{
    par[u] = p;
    rt[u] = root;
    // cout << s << u << " " << p << "\n";
    for (auto v : adj[u])
    {
        if (found)
            return;

        if (par[v] != -1 && rt[v] != root && rt[v] != -1)
        {
            t = v;
            v1 = par[v];
            v2 = u;
            found = 1;
            return;
        }
        if (par[v] == -1)
        {
            if (v == src)
                continue;
            if (p == -1)
                dfs(v, u, ++cnt);
            else
                dfs(v, u, root);
        }
    }
    return;
}
void solve()
{
    cin >> n >> m >> src;
    adj = vector<vector<int>>(n + 1, vector<int>());
    par = vector<int>(n + 1, -1);
    rt = vector<int>(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(src);
    if (t == -1)
        cout << "Impossible\n";
    else
    {
        cout << "Possible\n";
        vector<int> fp;
        fp.push_back(t);
        while (v1 != src)
        {
            fp.push_back(v1);
            v1 = par[v1];
        }
        fp.push_back(src);

        vector<int> sp;
        sp.push_back(t);
        while (v2 != src)
        {
            sp.push_back(v2);
            v2 = par[v2];
        }
        sp.push_back(src);

        reverse(fp.begin(), fp.end());
        reverse(sp.begin(), sp.end());
        cout << fp.size() << "\n";
        for (auto i : fp)
            cout << i << " ";
        cout << "\n";
        cout << sp.size() << "\n";
        for (auto i : sp)
            cout << i << " ";
        cout << "\n";
    }
    // for (int i = 0; i <= n; i++)
    //     cout << "par[" << i << "] = " << par[i] << "\n";
    // for (int i = 0; i <= n; i++)
    //     cout << "root[" << i << "] = " << rt[i] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}