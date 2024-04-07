#include <bits/stdc++.h>
using namespace std;
vector<int> v, taken, paired, degree;
vector<vector<int>> adj;
int n, m, mn = 100000000, tot_size;
void recurse()
{
    if (paired.size() == tot_size)
    {
        int tot = 0;
        for (int i = 1; i < tot_size; i += 2)
            tot += adj[paired[i - 1]][paired[i]];
        mn = min(mn, tot);
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (!taken[i])
        {
            taken[i] = 1;
            for (int j = i + 1; j < v.size(); j++)
            {
                if (!taken[j])
                {
                    taken[j] = 1;
                    paired.push_back(v[i]);
                    paired.push_back(v[j]);
                    recurse();
                    paired.pop_back();
                    paired.pop_back();
                    taken[j] = 0;
                }
            }
            taken[i] = 0;
            break;
        }
    }
}
vector<int> visited;
void dfs(int u)
{
    visited[u] = 1;
    for (int v = 1; v <= n; v++)
        if (!visited[v] && adj[u][v] != 100000000)
            dfs(v);
}
void solve()
{
    cin >> n >> m;
    visited = vector<int>(n + 1, 0);
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 100000000));
    degree = vector<int>(n + 1, 0);
    long long ans = 0;
    vector<int> found(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        found[u] = 1;
        found[v] = 1;
        ans += w;
        degree[u]++;
        degree[v]++;
        adj[u][v] = adj[v][u] = min(w, adj[u][v]);
    }
    dfs(1);
    if (m && (!found[1] || count(visited.begin(), visited.end(), 1) != count(found.begin(), found.end(), 1)))
    {
        cout << "-1\n";
        return;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                int c = adj[i][k] + adj[k][j];
                adj[i][j] = adj[j][i] = min(adj[i][j], c);
            }

    for (int i = 1; i <= n; i++)
        if (degree[i] & 1)
            v.push_back(i);
    tot_size = v.size();

    taken = vector<int>(v.size(), 0);
    recurse();
    ans += (mn == 100000000 ? 0 : mn);
    cout << ans << "\n";
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

/*

1 2  3 4
1 3  2 4
1 4  2 3

*/