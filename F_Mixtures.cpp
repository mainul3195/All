#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
vector<vector<long long>> dp;
long long sum(int a, int b)
{
    if (a > b)
        return 0;
    if (!a)
        return v[b] % 100;
    return (v[b] - v[a - 1]) % 100;
}
long long okdone(int i = 0, int j = n - 1)
{
    // cout << i << " " << j << "\n";
    if (i == j)
        return 0;
    if (~dp[i][j])
        return dp[i][j];
    long long ans = 922337203684775807;
    for (int k = i; k < j; k++)
        ans = min(ans, okdone(i, k) + okdone(k + 1, j) + sum(i, k) * sum(k + 1, j));
    // cout << i << " " << j << " " << ans << "\n";
    return dp[i][j] = ans;
}
void solve()
{
    v = vector<long long>(n);
    dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1));
    for (auto &i : v)
        cin >> i;
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    cout << okdone() << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n)
        solve();
    return 0;
}