#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, n;
    cin >> k >> n;
    for (int i = k; i > 0; i--)
    {
        if (1 + i * (i - 1) / 2 <= n && (1 + i * (i - 1) / 2) + k - i <= n)
        {
            int inc = 0, prev = 1;
            for (int j = 1; j <= i; j++)
            {
                int cur = prev + inc;
                cout << cur << " ";
                prev = cur;
                inc++;
            }
            for (int j = n - (k - i) + 1; j <= n; j++)
                cout << j << " ";
            cout << "\n";
            return;
        }
    }
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