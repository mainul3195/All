#include <bits/stdc++.h>
using namespace std;
vector<int> coins = {1, 5, 10, 25, 50};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 7489;
    vector<long long> dp(n + 100, 0);
    dp[0] = 1;
    for (auto val : coins)
        for (int i = 1; i <= n; i++)
            if (val <= i)
                dp[i] += dp[i - val];
    while (cin >> n)
        cout << dp[n] << "\n";
    return 0;
}