#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (
        (y - x >= 0 && (y - x) % (2 * (n - 1)) == 0) ||
        (x + y - 2 * n >= 0 && (x + y - 2 * n) % (2 * (n - 1)) == 0) ||
        ((x + y - 2) % (2 * (m - 1)) == 0) ||
        (x - y >= 0 && (x - y) % (2 * (m - 1)) == 0) || x==1 || y==m)
        cout << "BestWishes\n";
    else
        cout << "Farewell\n";

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