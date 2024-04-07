#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[a, b] : v)
        cin >> a;
    for (auto &[a, b] : v)
        cin >> b;
    sort(v.begin(), v.end());
    for (auto [a, b] : v)
        cout << a << " ";
    cout << "\n";
    for (auto [a, b] : v)
        cout << b << " ";
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