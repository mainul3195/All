#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> col;
bool possible(int u, int c)
{
    if (~col[u])
        return (col[u] == c ? 1 : 0);
    col[u] = c;
    bool ok = 1;
    for (auto v : adj[u])
        ok &= possible(v, !c);
    return ok;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n)
    {
        cin >> m;
        adj = vector<vector<int>>(n, vector<int>());
        col = vector<int>(n, -1);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (possible(0, 1))
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}