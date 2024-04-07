#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    long long count = 0;
    long long ans = 0;
    long long low = k * (k - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > q)
        {
            long long len = count - k + 1;
            if (len > 0)
                ans += len * (len + 1) / 2;
            count = 0;
        }
        else
            count++;
    }
    if (count)
    {
        long long len = count - k + 1;
        if (len > 0)
            ans += len * (len + 1) / 2;
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