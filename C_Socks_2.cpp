#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
vector<vector<int>> dp;
int okdone(int i = 0, int bad = 0)
{
    if (i == k)
    {
        if (bad)
            return 0;
        return 2000000000;
    }
    if (~dp[i][bad])
        return dp[i][bad];
    int ans = 0;
    if (!bad)
    {
        int ans1 = 0, ans2 = 0;
        if (i & 1)
            ans1 = v[i] - v[i - 1] + okdone(i + 1, bad);
        else
            ans1 = okdone(i + 1, bad);

        if (i & 1)
            ans2 = v[i + 1] - v[i - 1] + okdone(i + 2, !bad);
        else
            ans2 = okdone(i + 1, !bad);
        ans = min(ans1, ans2);
    }
    else
    {
        if (i & 1)
            ans = okdone(i + 1, bad);
        else
            ans = v[i] - v[i - 1] + okdone(i + 1, bad);
    }
    return dp[i][bad] = ans;
}
void solve()
{
    cin >> n >> k;
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    if (k & 1)
    {
        dp = vector<vector<int>>(n, vector<int>(2, -1));
        cout << okdone() << "\n";
    }
    else
    {
        int ans = 0;
        for (int i = 1; i < v.size(); i += 2)
            ans += v[i] - v[i - 1];
        cout << ans << "\n";
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