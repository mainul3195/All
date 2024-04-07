#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if ((b % 3 != 0) && ((c == 0) || ((b % 3 == 1 && c < 2)) || ((b % 3 == 2) && c < 1)))
        cout << "-1\n";
    else
        cout << (a + ((b + c + 2) / 3)) << "\n";
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