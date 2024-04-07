#include <bits/stdc++.h>
using namespace std;
vector<long long> cost;
vector<string> s;
vector<vector<long long>> dp;
string Reverse(string tmp)
{
    reverse(tmp.begin(), tmp.end());
    return tmp;
}
int n;
long long okdone(int prev = 0, int ind = 0)
{
    if (ind == n)
        return 0;
    if (~dp[prev][ind])
        return dp[prev][ind];
    string ps;
    if (!ind)
        ps = "";
    else if (!prev)
        ps = s[ind - 1];
    else
        ps = Reverse(s[ind - 1]);
    long long tot = 500000000000000;
    if (ps <= s[ind])
        tot = okdone(0, ind + 1);
    if (ps <= Reverse(s[ind]))
        tot = min(tot, cost[ind] + okdone(1, ind + 1));
    return dp[prev][ind] = tot;
}
void solve()
{
    cin >> n;
    cost = vector<long long>(n);
    s = vector<string>(n);
    dp = vector<vector<long long>>(2, vector<long long>(n + 1, -1));
    for (auto &i : cost)
        cin >> i;
    for (auto &i : s)
        cin >> i;
    long long tmp = okdone();
    if (tmp == 500000000000000)
        cout << "-1\n";
    else
        cout << tmp << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}