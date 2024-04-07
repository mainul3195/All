#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[1003][1003];
long long okdone(int n, int k)
{
    if (n <= 0)
        return 0;
    if (k == 0)
        return 1;
    if (~dp[n][k])
        return dp[n][k];
    long long res = 0;
    for (int i = n - 2; i >= 1; i--)
        res += (n - i - 1) * okdone(i, k - 1) % mod;
    return dp[n][k] = res % mod;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, m, k;
    cin >> n >> m >> k;
    cout << (okdone(n, k) * okdone(m, k)) % mod;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}