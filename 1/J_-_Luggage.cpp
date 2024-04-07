#include <bits/stdc++.h>
using namespace std;
int tot, sz;
vector<int> w;
vector<vector<int>> dp;
bool possible(int i = 0, int rem = tot / 2)
{
    if(i>=sz)
        return 0;
    if(!rem)
        return 1;
    if(rem<0)
        return 0;
    if(~dp[i][rem])
        return dp[i][rem];
    return dp[i][rem] = (possible(i + 1, rem - w[i])|possible(i+1, rem));
}
void solve()
{
    w.clear();
    int n;
    char c;
    do
    {
        cin >> n;
        w.push_back(n);
    } while (scanf("%c", &c) != EOF && c != '\n');
    tot = 0;
    for (auto i : w)
        tot += i;
    if (tot & 1)
    {
        cout << "NO\n";
        return;
    }
    sz = w.size();
    dp = vector<vector<int>>(sz + 1, vector<int>(tot / 2 + 1, -1));
    if (possible())
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}