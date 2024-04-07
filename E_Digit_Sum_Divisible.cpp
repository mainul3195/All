#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<vector<vector<int>>>> dp;
string s;
int sum;
string nw;
long long okdone(int i, int digit_sum, int num, int has_started)
{
    if (i == s.size())
        return num == 0 && digit_sum == sum;
    if (~dp[i][digit_sum][num][has_started])
        return dp[i][digit_sum][num][has_started];
    int ans = 0, lim = 9, d = s[i] - '0';
    if (!has_started)
        lim = d;
    for (int cur_d = 0; cur_d <= lim; cur_d++)
    {
        if (digit_sum + cur_d > sum)
            break;
        nw += (char)(cur_d + '0');
        ans += okdone(i + 1, digit_sum + cur_d, (num * 10 + cur_d) % sum, has_started || cur_d < d);
        nw.pop_back();
    }
    return dp[i][digit_sum][num][has_started] = ans;
}
void solve()
{
    cin >> s;
    long long ans = 0;
    for (sum = 1; sum <= 127; sum++)
    {
        dp = vector<vector<vector<vector<int>>>>(s.size(), vector<vector<vector<int>>>(sum + 1, vector<vector<int>>(sum + 1, vector<int>(2, -1))));
        ans += okdone(0, 0, 0, 0);
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}