#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s, r;
    cin >> n >> s >> r;
    cout << s - r << " ";
    n--;
    s = r;
    int extra = s % n;
    for (int i = 0; i < extra; i++)
        cout << (s / n + 1) << " ";
    for (int i = 0; i < n - extra; i++)
        cout << (s / n) << " ";
    cout << "\n";
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