#include <bits/stdc++.h>
using namespace std;
int k, n;
vector<int> w, v;
vector<vector<int>> dp;
int solve(int i = 0, int rem = k)
{
    if (i == n || !rem)
        return 0;
    if (~dp[i][rem])
        return dp[i][rem];

    return dp[i][rem] = max(w[i] <= rem ? solve(i + 1, rem - w[i]) + v[i] : 0, solve(i + 1, rem));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    w = vector<int>(n);
    v = vector<int>(n);
    dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << solve() << "\n";
    return 0;
}