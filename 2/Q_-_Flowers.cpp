#include <bits/stdc++.h>
using namespace std;
int k;
vector<long long> dp;
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    cout << (dp[b] - dp[a - 1] + 1000000007) % 1000000007 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, k;
    cin >> t >> k;
    dp = vector<long long>(100005, 0);
    for (int i = 0; i < k; i++)
        dp[i] = 1;
    for (int i = k; i <= 100003; i++)
        dp[i] = (dp[i - 1] + dp[i - k]) % 1000000007;
    for (int i = 1; i <= 100003; i++)
        dp[i] = (dp[i] + dp[i - 1]) % 1000000007;
    while (t--)
        solve();
    return 0;
}