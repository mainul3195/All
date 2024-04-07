#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long okdone(int prev, int rem)
{
    if (~dp[prev][rem])
        return dp[prev][rem];
    long long tot = 1;
    for (int i = prev + 1; rem - i > i; i++)
        tot += okdone(i, rem - i);
    return dp[prev][rem] = tot;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1));
    cout << okdone(0, n) - 1;
    return 0;
}