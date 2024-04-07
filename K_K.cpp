#include <bits/stdc++.h>
using namespace std;
#define pi (2 * acos(0.0))
void solve()
{
    double d, l;
    cin >> d >> l;
    double a = d / 2 + (l - d) / 2;
    double b = sqrt((l / 2) * (l / 2) - (d / 2) * (d / 2));
    cout << fixed << setprecision(3) << pi * a * b << "\n";
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