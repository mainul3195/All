#include<bits/stdc++.h>
using namespace std;
int n, m;
#define inf 10000000
#define int long long
vector<vector<pair<int, int>>>adj;
vector<int>dis1, dis2;
void find_dist(int start, vector<int>&dis)
{
    dis[start] = 0;
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
    q.push({0, start});
    while(q.size())
    {
        auto [w, u] = q.top();
        q.pop();
        for(auto [v, cost]: adj[u])
        {
            int tot = cost+w;
            if(tot<dis[v])
            {
                dis[v] = tot;
                q.push({tot, v});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int, int>>> (n+1, vector<pair<int, int>>());
    dis1 = vector<int> (n+1);
    dis2 = vector<int> (n+1);
    for(auto &i: dis1)
        i = inf;
    for(auto &i: dis2)
        i = inf;
    for(int i = 0; i<m; i++)
    {
        int u, v, w;
        cin >> u>> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    find_dist(1, dis1);
    find_dist(n, dis2);
    int ans = inf;
    for(int u = 1; u<=n; u++)
    {
        for(auto [v, w]: adj[u])
        {
            int cost = dis1[u]+dis2[v]+w;
            if(cost>dis1[n])
                ans = min(ans, cost);
        }
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}