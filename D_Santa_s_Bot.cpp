#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    long long tmp = bigMod(b, p / 2);
    tmp = tmp * tmp % mod;
    if (p & 1)
        tmp = tmp * b % mod;
    return tmp;
}
int cnt[1000006];
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            cnt[x]++;
            v[i].push_back(x);
        }
    }
    long long ans = 0, mdinverse_n = bigMod(n, mod - 2);
    for (int i = 0; i < n; i++)
    {
        int tot = 0;
        for (auto j : v[i])
            tot += cnt[j];
        ans = (ans + tot * mdinverse_n % mod * mdinverse_n % mod * bigMod(v[i].size(), mod - 2)) % mod;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}