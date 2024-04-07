#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<vector<pair<int, int>>> adj;
vector<int> A, B;

void first_dfs(int u = a, int p = -1, int x = 0)
{
    A.push_back(x);
    for (auto [v, w] : adj[u])
        if (v != b && v != p)
            first_dfs(v, u, x ^ w);
}

void Second_dfs(int u = b, int p = -1, int x = 0)
{
    if (u != b)
        B.push_back(x);
    for (auto [v, w] : adj[u])
        if (v != p)
            Second_dfs(v, u, x ^ w);
}
void init()
{
    A.clear();
    B.clear();
    cin >> n >> a >> b;
    adj = vector<vector<pair<int, int>>>(n + 1);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        init();
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }
        Second_dfs();
        first_dfs();
        sort(B.begin(), B.end());
        sort(A.begin(), A.end());

        for (auto nm : A)
        {
            auto iter = lower_bound(B.begin(), B.end(), nm);
            if (iter != B.end() && *iter == nm)
            {
                cout << "YES\n";
                goto mainul;
            }
        }
        cout << "NO\n";
    mainul:
    {
    }
    }
    return 0;
}