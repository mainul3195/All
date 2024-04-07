#include <bits/stdc++.h>
using namespace std;
vector<int> values, avail, taken;
vector<long long> dp;
#define lim 100005
int q;
long long v;

long long ans;
void make_ans(int i = 0)
{
    if (i == 4)
    {
        long long sum = 0;
        for (auto j : taken)
            sum += (avail[j] + 1) * values[j];
        if (sum > v)
            return;
        if (taken.size() & 1)
            ans -= max(0LL, dp[v - sum]);
        else
            ans += max(0LL, dp[v - sum]);
        return;
    }
    make_ans(i + 1);
    taken.push_back(i);
    make_ans(i + 1);
    taken.pop_back();
}

void solve()
{
    values = vector<int>(4);
    dp = vector<long long>(lim + 1, 0);
    dp[0] = 1;
    for (auto &i : values)
        cin >> i;
    cin >> q;
    for (int i = 0; i < 4; i++)
        for (int j = values[i]; j < lim; j++)
            dp[j] += dp[j - values[i]];
    while (q--)
    {
        avail = vector<int>(4);
        for (auto &i : avail)
            cin >> i;
        cin >> v;
        taken.clear();
        ans = 0;
        make_ans();
        cout << ans << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}