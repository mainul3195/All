#include <bits/stdc++.h>
using namespace std;
#define int long long
int egcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
void solve()
{
    int x, k;
    cin >> x >> k;
    int p, q;
    int g = egcd(x / k, (x + k - 1) / k, p, q);
    p = p * x / g;
    q = q * x / g;
    cout << p << " " << q << "\n";
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