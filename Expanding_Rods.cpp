#include <bits/stdc++.h>
using namespace std;

void solve()
{
    double l, n, c;
    cin >> l >> n >> c;
    double s = (1 + n * c) * l;
    double st = 0, e = l / 2, h;
    int count = 100;
    while (count--)
    {
        h = (st + e) / 2;
        double r = l * l / (8 * h) + h / 2;
        double theta = 2 * asin(l / (2 * r));
        double nl = 2 * r * sin(s / (2 * r));
        if (nl > l)
            st = h;
        else
            e = h;
    }
    cout << fixed << setprecision(8) << h << "\n";
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
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}