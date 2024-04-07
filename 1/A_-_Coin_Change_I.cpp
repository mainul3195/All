#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<long long> val, num;
vector<vector<long long>> dp;
int ok_done(int i = 0, int rem = k)
{
    if (rem == 0)
        return 1;
    if (rem < 0 || i >= n)
        return 0;
    if (~dp[i][rem])
        return dp[i][rem];
    long long tot = 0;
    for (int j = 0; j <= num[i]; j++)
        tot = (tot + ok_done(i + 1, rem - j * val[i])) % 100000007;
    return dp[i][rem] = tot;
}
void solve()
{
    cin >> n >> k;
    val = vector<long long>(n);
    num = vector<long long>(n);
    dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1, -1));
    for (auto &i : val)
        cin >> i;
    for (auto &i : num)
        cin >> i;
    cout << ok_done() << "\n";
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