#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> ans;
int n, root;
vector<int> par, cur;
void dfs(int u, int p)
{
    cur.push_back(u);
    int child = 0;
    for (auto v : adj[u])
    {
        if (v != p)
        {
            child++;
            dfs(v, u);
        }
    }
    if (!child)
    {
        ans.push_back(cur);
        cur.clear();
    }
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n, vector<int>());
    par = vector<int>(n);
    for (auto &i : par)
    {
        cin >> i;
        i--;
    }

    for (int i = 0; i < n; i++)
    {
        if (par[i] == i)
            root = i;
        else
            adj[par[i]].push_back(i);
    }
    dfs(root, -1);
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i.size() << "\n";
        for (auto k : i)
            cout << k + 1 << " ";
        cout << "\n";
    }
    ans.clear();
    cout << "\n";
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