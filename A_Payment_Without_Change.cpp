#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, n, s;
    cin >> a >> b >> n >> s;
    int t = min(a, s / n) * n;
    if (b >= s - t)
        cout << "YES\n";
    else
        cout << "NO\n";
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