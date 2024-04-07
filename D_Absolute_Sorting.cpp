#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<pair<int, int>> p;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
            p.push_back({1, 1000000000});
        else if (v[i] > v[i - 1])
            p.push_back({1, (v[i] + v[i - 1]) / 2});
        else
            p.push_back({(v[i] + v[i - 1] + 1) / 2, 1000000000});
    }
    int r = 1000000000, l = 1;
    for (auto [a, b] : p)
        l = max(l, a), r = min(r, b);
    if (l > r)
        cout << "-1\n";
    else
        cout << l << "\n";
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