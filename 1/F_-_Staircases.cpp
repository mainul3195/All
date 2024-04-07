#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<long long>> dp;
long long okdone(int prev = 0, int rem = n)
{
    if (~dp[prev][rem])
        return dp[prev][rem];
    if (!rem)
        return 1;
    if (rem <= prev)
        return 0;
    long long tot = 0;
    for (int i = prev + 1; i <= rem; i++)
        tot += okdone(i, rem - i);
    return dp[prev][rem] = tot;
}
void solve()
{
    cin >> n;
    dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1));
    cout << okdone() - 1 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}