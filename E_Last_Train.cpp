#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LONG_LONG_MAX
struct nd
{
    long long l, d, k, c, v;
};
int n, m;
vector<vector<nd>> info;
vector<long long> ans;
void solve()
{
    cin >> n >> m;
    info = vector<vector<nd>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int l, d, k, c, u, v;
        cin >> l >> d >> k >> c >> u >> v;
        info[v].push_back({l, d, k, c, u});
    }
    ans = vector<long long>(n + 1, -1);
    ans[n] = inf;
    priority_queue<pair<long long, int>> q;
    q.push({inf, n});
    while (q.size())
    {
        auto [cur, v] = q.top();
        q.pop();
        // cout << v << " -> ";
        for (auto [a, d, k, c, u] : info[v])
        {
            long long x = cur - c;
            if (x - a < 0)
                continue;
            long long tmp = ans[u];
            ans[u] = max(ans[u], a + min((k - 1) * d, (x - a) / d * d));
            if (ans[u] != tmp)
                q.push({ans[u], u});
        }
        // for (int i = 1; i < n; i++)
        //     cout << ans[i] << " ";
        // cout << "\n";
    }
    for (int i = 1; i < n; i++)
    {
        if (ans[i] == -1)
            cout << "Unreachable\n";
        else
            cout << ans[i] << "\n";
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