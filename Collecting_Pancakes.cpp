#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n + 1, 0), ori(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        ori[i] = v[i];
        v[i] += v[i - 1];
    }
    // for (auto i : ori)
    //     cout << i << " ";
    // cout << "\n";
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "\n";
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;
    if (ra < lb)
        cout << v[ra + (lb - ra) / 2] << "\n";
    else if (la > rb)
        cout << v[n] - v[la - (la - rb) / 2 - 1] << "\n";
    else
    {
        int l = max(la, lb);
        int r = min(ra, rb);
        long long ans = 0;
        for (int i = l; i <= r; i++)
        {
            long long left, right;
            left = right = 9223372036854775807;
            left = v[i - 1];
            right = v[n] - v[i];
            if (i == lb)
                ans = max(ans, ori[i] + left);
            else if (i == rb)
                ans = max(ans, ori[i] + right);
            else
                ans = max(ans, ori[i] + min(left, right));
        }
        cout << ans << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}