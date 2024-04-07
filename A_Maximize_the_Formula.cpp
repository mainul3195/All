#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v(3);
    for (auto &i : v)
        cin >> i;
    sort(v.rbegin(), v.rend());
    cout << 10 * v[0] + v[1] + v[2] << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}