#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<int> l, r;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        l.insert(x);
        r.insert(y);
        v.push_back({x, y});
    }
    int mx = 0;
    for (auto [x, y] : v)
    {
        l.erase(l.find(x));
        r.erase(r.find(y));
        mx = max(mx, *r.begin() - *l.rbegin());
        l.insert(x);
        r.insert(y);
    }
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