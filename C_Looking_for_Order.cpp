#include <bits/stdc++.h>
using namespace std;
struct pt
{
    int x, y;
    int dist(const pt &b) const
    {
        return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
    }
};
vector<pt> v;
vector<int> path, dp;
int mntime = 1000000000;
pt init;
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> init.x >> init.y >> n;
    v = vector<pt>(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    dp = path = vector<int>((1 << n) + 1);
    dp[0] = 0;
    int lim = (1 << n);
    for (int mask = 1; mask < lim; mask++)
    {
        int j = n - 1;
        while (!(mask & (1 << j)))
            j--;
        dp[mask] = 2 * init.dist(v[j]) + dp[mask ^ (1 << j)];
        path[mask] = mask ^ (1 << j);
        for (int i = 0; i < j; i++)
            if (mask & (1 << i))
            {
                int tmp = mask;
                tmp ^= (1 << j);
                tmp ^= (1 << i);
                int dis = init.dist(v[i]) + init.dist(v[j]) + v[i].dist(v[j]) + dp[tmp];
                if (dis < dp[mask])
                {
                    dp[mask] = dis;
                    path[mask] = tmp;
                }
            }
    }
    cout << dp[(1 << n) - 1] << "\n";
    int prev = (1 << n) - 1;
    int cur;
    cout << "0 ";
    do
    {
        cur = path[prev];
        int x = cur ^ prev;
        for (int i = 0; i < n; i++)
            if (x & (1 << i))
                cout << i + 1 << " ";
        cout << "0 ";
        prev = cur;
    } while (prev);
    return 0;
}