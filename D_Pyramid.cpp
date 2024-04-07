#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), pir(n, 1000000000);
    for (auto &i : v)
        cin >> i;
    pir[0] = 1;
    for (int i = 1; i < n; i++)
        pir[i] = min(pir[i - 1] + 1, v[i]);
    pir[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        pir[i] = min({pir[i], pir[i + 1] + 1, v[i]});
    int mx = -1;
    for (auto i : pir)
        mx = max(mx, i);
    cout << mx << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}