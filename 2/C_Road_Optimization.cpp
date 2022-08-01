#include <bits/stdc++.h>
using namespace std;
long long n, l, k;
vector<long long> pos, val;
vector<vector<long long>> dp;
long long okdone(int i, int r)
{
    if (~dp[i][r])
        return dp[i][r];
    if (i == n)
        return 0;
    long long ans = 9223372036854775;
    for (int j = i + 1; j-i <= r + 1 && j <= n; j++)
        ans = min(ans, (pos[j] - pos[i]) * val[i] + okdone(j, r - j + i + 1));
    return dp[i][r] = ans;
}
void solve()
{
    cin >> n >> l >> k;
    pos = vector<long long>(n);
    val = vector<long long>(n);
    dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1));
    for (auto &i : pos)
        cin >> i;
    for (auto &i : val)
        cin >> i;
    pos.push_back(l);
    cout << okdone(0, k) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}