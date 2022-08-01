#include <bits/stdc++.h>
using namespace std;
long long dp[4][21], n;
vector<vector<long long>> cost;
long long okdone(int prev = 3, int i = 0)
{
    if (i == n)
        return 0;
    if(~dp[prev][i])
        return dp[prev][i];
    long long ans = 1000000000;
    for (int j = 0; j < 3; j++)
        if (prev != j)
            ans = min(ans, cost[i][j] + okdone(j, i + 1));
    return dp[prev][i] = ans;
}
void solve()
{
    cin >> n;
    cost = vector<vector<long long>>(n, vector<long long>(3));
    for (auto &i : cost)
        for (auto &j : i)
            cin >> j;
    memset(dp, -1, sizeof(dp));
    cout << okdone() << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}