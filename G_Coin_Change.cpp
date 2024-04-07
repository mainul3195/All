#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
int n;
vector<int> types = {1, 5, 10, 25, 50};
long long solve(int i = 0, int rem = n)
{
    if (!rem)
        return 1;
    if (i == 5)
        return 0;
    if (~dp[i][rem])
        return dp[i][rem];
    long long tot = 0;
    for (int j = 0; types[i] * j <= rem; j++)
        tot += solve(i + 1, rem - types[i] * j);
    return dp[i][rem] = tot;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp = vector<vector<long long>>(5, vector<long long>(8000, -1));
    while (cin >> n)
    {
        cout << solve() << "\n";
    }
    return 0;
}