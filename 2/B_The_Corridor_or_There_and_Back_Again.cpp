#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int mn = 1000000;
    for (int i = 0; i < n; i++)
    {
        int d, s;
        cin >> d >> s;
        mn = min(d + (s + 1) / 2 - 1, mn);
    }
    cout << mn << "\n";
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