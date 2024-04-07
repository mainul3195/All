#include <bits/stdc++.h>
using namespace std;
int l, n;
vector<int> pos;
vector<vector<int>> dp;
int okdone(int s = 0, int e = pos.size() - 1)
{
    if (s + 1 == e)
        return 0;
    if (~dp[s][e])
        return dp[s][e];
    int mn = 2000000000;
    for (int i = s + 1; i < e; i++)
        mn = min(mn, okdone(s, i) + okdone(i, e));
    return dp[s][e] = pos[e] - pos[s] + mn;
}
void solve()
{
    cin >> n;
    dp = vector<vector<int>>(l + 2, vector<int>(l + 2, -1));
    pos.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos.push_back(x);
    }
    pos.push_back(l);
    cout << "The minimum cutting is " << okdone() << ".\n";
    pos.clear();
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> l && l)
        solve();
    return 0;
}