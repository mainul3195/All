#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000
struct nd
{
    int u;
    long long cost;
    int remaining_fuel;
    bool operator<(const nd &a) const
    {
        return cost > a.cost;
    }
};
int n, m, q, capacity, start, destination;
vector<long long> fuel_cost;
vector<vector<long long>> tot_cost;
vector<vector<pair<int, int>>> adj;
void solve()
{
    cin >> n >> m;
    fuel_cost = vector<long long>(n);
    adj = vector<vector<pair<int, int>>>(n);
    for (auto &i : fuel_cost)
        cin >> i;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> q;
    while (q--)
    {
        cin >> capacity >> start >> destination;
        tot_cost = vector<vector<long long>>(n, vector<long long>(capacity + 1, inf));
        priority_queue<nd> q;
        tot_cost[start][0] = 0;
        q.push({start, 0, 0});
        bool done = 0;
        while (q.size())
        {
            auto [u, cost, remaining] = q.top();
            q.pop();
            if (u == destination)
            {
                cout << cost << "\n";
                done = 1;
                break;
            }
            if (remaining + 1 <= capacity && tot_cost[u][remaining + 1] > tot_cost[u][remaining] + fuel_cost[u])
            {
                tot_cost[u][remaining + 1] = tot_cost[u][remaining] + fuel_cost[u];
                q.push({u, tot_cost[u][remaining + 1], remaining + 1});
            }
            for (auto [v, d] : adj[u])
                if (d <= remaining && tot_cost[v][remaining - d] > tot_cost[u][remaining])
                {
                    tot_cost[v][remaining - d] = tot_cost[u][remaining];
                    q.push({v, cost, remaining - d});
                }
        }
        if (!done)
            cout << "impossible\n";
    }
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
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}