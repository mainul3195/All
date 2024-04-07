#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<long long> dp;

void solve()
{
    cin >> n >> k;
    dp = vector<long long>(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        for (int j = coin; j <= k; j++)
            dp[j] = (dp[j] + dp[j - coin]) % 100000007;
    }
    cout << dp[k] << "\n";
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
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}