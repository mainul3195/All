#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
string a, b;
#define mod 1000000007
long long okDone(int i, int j)
{
    if (j == 0)
        return 1;
    if (j > i)
        return 0;
    if (~dp[i][j])
        return dp[i][j];
    if (a[i - 1] == b[j - 1])
        return dp[i][j] = (okDone(i - 1, j - 1) + okDone(i - 1, j)) % mod;
    return dp[i][j] = okDone(i - 1, j) % mod;
}
void solve()
{
    while (cin >> a >> b)
    {
        dp = vector<vector<long long>>(a.size() + 1, vector<long long>(b.size() + 1, -1));
        cout << okDone(a.size(), b.size()) << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}