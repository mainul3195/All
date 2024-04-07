#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a >= d || b <= c)
        cout << d - c + b - a << "\n";
    else
        cout << max(b, d) - min(a, c) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    solve();
    return 0;
}