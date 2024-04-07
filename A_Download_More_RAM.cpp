#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    vector<pair<int, int>> itm;
    for (int i = 0; i < n; i++)
        itm.push_back({a[i], b[i]});
    sort(itm.begin(), itm.end());
    long long cur = k;
    for (int i = 0; i < n; i++)
    {
        auto [f, s] = itm[i];
        if (f > cur)
            break;
        cur += s;
    }
    cout << cur << "\n";
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