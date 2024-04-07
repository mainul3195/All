#include <bits/stdc++.h>
using namespace std;
int n;
long long bit[100005];
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= n; x += (x & (-x)))
        bit[x] += val;
}
void solve()
{
    cin >> n;
    memset(bit, 0, (n + 2) * 8);
    vector<int> a(n), b(n), pos(n + 1);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    for (int i = 0; i < n; i++)
        pos[b[i]] = i + 1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += qr(n) - qr(pos[a[i]] - 1);
        upd(pos[a[i]], 1);
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