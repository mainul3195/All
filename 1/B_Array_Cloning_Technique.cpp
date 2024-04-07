#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int mx = 0;
    for (auto [a, b] : mp)
        mx = max(mx, b);
    int ans = 0;
    while (mx < n)
    {
        ans++;
        int tmp = min(mx, n - mx);
        mx += tmp;
        ans += tmp;
    }
    cout << ans << "\n";
    return;
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