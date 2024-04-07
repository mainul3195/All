#include <bits/stdc++.h>
using namespace std;
bool pos(int m, long long x, long long y)
{
    for (int i = 0; i <= m; i++)
    {
        long long d = y + i, dv = x;
        for (int j = i; j < m; j++)
            dv /= d;
        if (!dv)
            return 1;
    }
    return 0;
}
void solve()
{
    long long a, b;
    cin >> a >> b;
    int ans = 30;
    for (int i = 32; i >= 0; i--)
        if (pos(i, a, b))
            ans = i;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}