#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i & 1)
            b[x]++;
        else
            a[x]++;
    }
    vector<pair<int, int>> va, vb;
    for (auto [i, j] : a)
        va.push_back({j, i});
    for (auto [i, j] : b)
        vb.push_back({j, i});
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    // for (auto [i, j] : va)
    //     cout << i << ": " << j << "\n";
    // for (auto [i, j] : vb)
    //     cout << i << " - " << j << "\n";
    if (va[0].second == vb[0].second)
    {
        if (va[0].first > vb[0].first)
            swap(va, vb);
        cout << (n / 2 - va[0].first + n / 2 - (vb.size() > 1 ? vb[1].first : 0)) << "\n";
    }
    else
        cout << ((n / 2) - va[0].first + (n / 2) - vb[0].first) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}