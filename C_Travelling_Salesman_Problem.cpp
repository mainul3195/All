// #include <bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int n;
//     cin >> n;
//     vector<pair<long long, long long>> v(n);
//     long long tot = 0;
//     for (auto &[a, c] : v)
//     {
//         cin >> a >> c;
//         tot += c;
//     }
//     sort(v.begin(), v.end());
//     vector<vector<pair<int, long long>>> adj(n);
//     for (int i = 0; i < n; i++)
//     {
//         if (i)
//             adj[i].push_back({i - 1, 0});
//         int l = i, r = n - 1, mid, ans = i;
//         while (l <= r)
//         {
//             mid = (l + r) / 2;
//             if (v[mid].first - v[i].first - v[i].second <= 0)
//             {
//                 ans = mid;
//                 l = mid + 1;
//             }
//             else
//                 r = mid - 1;
//         }
//         if (ans != i)
//             adj[i].push_back({ans, 0});
//         if (ans != n - 1)
//             adj[i].push_back({ans + 1, v[ans + 1].first - v[i].first - v[i].second});
//     }
//     vector<long long> dist(n, 10000000000000000);
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
//     q.push({0, 0});
//     while (q.size())
//     {
//         auto [c, u] = q.top();
//         q.pop();
//         if (dist[u] < c)
//             continue;
//         for (auto [v, w] : adj[u])
//         {
//             long long tmp_cost = c + w;
//             if (tmp_cost < dist[v])
//             {
//                 dist[v] = tmp_cost;
//                 q.push({tmp_cost, v});
//             }
//         }
//     }
//     cout << tot + dist[n - 1] << "\n";
// }
// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    long long ans = 0;
    for (auto &[a, c] : v)
    {
        cin >> a >> c;
        ans += c;
    }
    sort(v.begin(), v.end());
    long long mx = -1;
    for (auto [a, c] : v)
    {
        if (!(~mx))
        {
            mx = a + c;
            continue;
        }
        ans += max(0LL, a - mx);
        mx = max(mx, a + c);
    }
    cout << ans << "\n";
    return 0;
}