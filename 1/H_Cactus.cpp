#include <bits/stdc++.h>
using namespace std;
unsigned long long ans;
bool found;
vector<vector<int>> adj;
int n, m;
vector<int> level;
void dfs(int u = 1, int par = -1)
{
    for (auto v : adj[u])
        if (v != par)
        {
            if (level[v])
            {
                if (level[v] < level[u])
                {
                    found = 1;
                    ans = ans * (level[u] - level[v] + 1);
                }
            }
            else
            {
                level[v] = level[u] + 1;
                dfs(v, u);
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        found = 0;
        ans = 1;
        cout << "Case " << ++tc << ": ";
        cin >> n >> m;
        adj = vector<vector<int>>(n + 1, vector<int>());
        level = vector<int>(n + 1, 0);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        level[1] = 1;
        dfs();

        cout << ans << "\n";
    }
    return 0;
}