#include <bits/stdc++.h>
using namespace std;
int n, k, mx, cnt;
vector<vector<int>> adj;
vector<int> depth;
void dfs(int u = 1, int h = 0)
{
    depth[h]++;
    for (auto v : adj[u])
        dfs(v, h + 1);
}
bool possible(int X)
{
    if (!X)
        return n == 1;
    cnt = 0;
    for (int i = X + 1; i <= n && depth[i]; i += X)
        cnt += depth[i];
    return cnt <= k;
}
void solve()
{
    cin >> n >> k;
    adj.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs();
    int l = 0, r = n, ans = -1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (possible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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

// 0
// 1
// 2

// 3
// 4

// 5
// 6

// 7
// 8

// 9