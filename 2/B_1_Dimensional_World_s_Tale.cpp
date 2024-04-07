#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int mx_x = -100000000, mn_y = 1000000000;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mx_x = max(mx_x, a);
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        mn_y = min(mn_y, a);
    }
    if (mx_x < min(y, mn_y) && min(y, mn_y) > x)
        cout << "No War\n";
    else
        cout << "War\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}