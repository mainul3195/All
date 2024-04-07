#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int oddc = 0;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        if (u & 1)
            oddc++;
    }
    if (((x + oddc) & 1) == (y & 1))
        cout << "Alice\n";
    else
        cout << "Bob\n";
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