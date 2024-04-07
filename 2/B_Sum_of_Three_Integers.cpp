#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long k, s;
    cin >> k >> s;
    long long ans = 0;
    for (int i = 0; i <= k; i++)
    {
        long long rem = s - i;
        if (rem >= 0)
            ans += max(0LL, rem + 1 - 2 * max(rem - k, 0LL));
        // cout << i << " -> " << ans << "\n";
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}