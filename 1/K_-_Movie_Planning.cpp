#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    int aft[m + 2] = {0}, strt[m + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        mp[l].push_back(r);
        strt[l] = 1;
    }
    aft[m + 1] = 0;
    for (int i = m; i >= 1; i--)
    {
        aft[i] = aft[i + 1];
        if (strt[i])
        {
            for (auto r : mp[i])
                aft[i] = (aft[i] + m - r + 1) % 1000000007;
        }
    }
    // for (int i = 0; i <= m; i++)
    //     cout << aft[i] << " ";
    // cout << "\n";
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (strt[i])
        {
            for (auto r : mp[i])
                ans = (ans + i * aft[r + 1]) % 1000000007;
        }
    }
    cout << ans << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}