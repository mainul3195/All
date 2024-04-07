#include <bits/stdc++.h>
using namespace std;
#define int long long
int okdone(int i, long long h, int g, int b, vector<int> &v, int n)
{
    if (i >= n || (v[i] >= h && !g && !b))
        return i;
    if (v[i] < h)
        return okdone(i + 1, h + v[i] / 2, g, b, v, n);
    int mx = i;
    if (g)
        mx = okdone(i, 2 * h, g - 1, b, v, n);
    if (b)
        mx = max(mx, okdone(i, 3 * h, g, b - 1, v, n));
    return mx;
}
void solve()
{
    long long n, h;
    cin >> n >> h;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    cout << okdone(0, h, 2, 1, v, n) << "\n";

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