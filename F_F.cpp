#include <bits/stdc++.h>
using namespace std;
long long dp[17][1 << 17];
int n, lim;
vector<pair<int, int>> points(17);
vector<int> taken;
long long okdone(int i, int mask)
{
    for (auto el : taken)
        cout << el << endl;

    cout << mask << " " << i << endl;
    if (i % 2 == 0 && mask & (1 << i))
    {
        if (taken[0] == i + 1)
        {
            taken[0] = taken.size() == 2 ? taken[1] : -1;
            taken.pop_back();
            mask ^= (1 << i);
        }
        else if (taken[1] == i + 1)
        {
            mask ^= (1 << i);
            taken.pop_back();
        }
    }
    if (!mask)
        return points[i].first + points[i].second;
    if (~dp[i][mask])
        return dp[i][mask];
    long long ans = 10000000000000000;
    if (taken.size() == 0)
    {
        for (int k = 1; k < lim; k++)
        {
            taken.push_back(k);
            ans = min(ans, abs(points[i].first - points[k].first) + abs(points[i].second - points[k].second) + okdone(k, mask ^ (1 << k)));
        }
    }
    else if(taken.size()==2)
    {
            ans = min(ans, abs(points[i].first - points[taken[0]-1].first) + abs(points[i].second - points[taken[0]-1].second) + okdone(taken[0]-1, mask));
    }
    // for (int k = 0; k < lim; k++)
    //     if (i != k)
    //     {
    //         if ((mask & (1 << k)))
    //         {
    //             ans = min(ans, abs(points[i].first - points[k].first) + abs(points[i].second - points[k].second) + okdone(k, mask));
    //             if (i & 1 && taken.size() < 2)
    //             {
    //                 taken.push_back(i);
    //                 ans = min(ans, abs(points[i].first - points[k].first) + abs(points[i].second - points[k].second) + okdone(k, mask ^ (1 << i)));
    //             }
    //         }
    //     }
    return dp[i][mask] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    points[16] = {0, 0};
    int mask = 0;
    lim = 2 * n;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points[2 * i] = {x1, y1};
        points[2 * i + 1] = {x2, y1};
        mask |= (1 << (2 * i));
        mask |= (1 << (2 * i + 1));
    }
    cout << mask << "\n";
    // cout << "ok\n";
    cout << okdone(16, mask) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}