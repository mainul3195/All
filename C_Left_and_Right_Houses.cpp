#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = -1;
    vector<int> lft(n + 2, 0), rght(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '0')
            lft[i] = 1;
        lft[i] += lft[i - 1];
    }
    for (int i = n; i; i--)
    {
        if (s[i - 1] == '1')
            rght[i] = 1;
        rght[i] += rght[i + 1];
    }
    int mn = 1000000000;
    int mid = 1 + n;
    for (int i = 0; i <= n; i++)
    {
        if (((i + 1) / 2 <= lft[i]) && ((n - i + 1) / 2 <= rght[i + 1]))
        {
            // cout << i << " -> ";
            int dis = abs(mid - ((2 * i) + 1));
            if (dis < mn)
            {
                mn = dis;
                ans = i;
                // cout << (i + 1) / 2 << " " << lft[i] << " " << (n - i + 1) / 2 << " " << rght[i + 1];
            }
            // cout << "\n";
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