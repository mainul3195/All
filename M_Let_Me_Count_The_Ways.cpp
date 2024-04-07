#include <bits/stdc++.h>
using namespace std;
vector<int> coins = {1, 5, 10, 25, 50};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        vector<long long> dp(n + 100, 0);
        dp[0] = 1;
        for (auto val : coins)
            for (int i = 1; i <= n; i++)
                if (val <= i)
                    dp[i] += dp[i - val];
        if (dp[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        else
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
    }
    return 0;
}