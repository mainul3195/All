#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<int> a, b;
vector<vector<long long>> dp;
long long okdone(int i, int state)
{
    if (~dp[i][state])
        return dp[i][state];
    if (!i)
    {
        if (state == 0)
            return dp[i][state] = a[i];
        else
            return dp[i][state] = c + b[i];
    }
    if (state == 0)
        return dp[i][state] = min(a[i] + okdone(i - 1, 0), a[i] + okdone(i - 1, 1));
    else
        return dp[i][state] = min(c + b[i] + okdone(i - 1, 0), b[i] + okdone(i - 1, 1));
    return 0;
}
void solve()
{
    cin >> n >> c;
    dp = vector<vector<long long>>(n - 1, vector<long long>(2, -1));
    a = vector<int>(n - 1);
    b = vector<int>(n - 1);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    okdone(n - 2, 0);
    okdone(n - 2, 1);
    cout << "0 ";
    for (int i = 0; i < n - 1; i++)
        cout << min(dp[i][0], dp[i][1]) << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}