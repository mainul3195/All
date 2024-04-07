#include <bits/stdc++.h>
using namespace std;
string s;
vector<vector<int>> dp;
bool is_greater(string a, string b)
{
    if (a.size() > b.size())
        return 0;
    if (a.size() < b.size())
        return 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (b[i] != a[i])
        {
            if (b[i] > a[i])
                return 1;
            return 0;
        }
    }
    return 0;
}
int okdone(int i = 0, int prev = 0)
{
    if (~dp[i][prev])
        return dp[i][prev];
    int can_take = 0;
    for (int len = prev; len - prev < 3; len++)
    {
        if (i + len <= s.size() && is_greater(s.substr(i - prev, prev), s.substr(i, len)))
            can_take = max(can_take, 1 + okdone(i + len, len));
    }
    return dp[i][prev] = can_take;
}
void solve()
{
    cin >> s;
    dp = vector<vector<int>>(s.size() + 1, vector<int>(min(100, (int)s.size()), -1));
    cout << okdone() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}